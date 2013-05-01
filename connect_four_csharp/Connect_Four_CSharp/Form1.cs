using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.IO;
using System.Reflection;



//IF YOU CREATE A CONTROL, NAME IT SOMETHING MEANINGFUL
//IF I SEE button01 ANYWHERE, SOMEONE WILL DIE

namespace Connect_Four_CSharp
{
    public partial class gameInterface : Form
    {
        bool gameStarted;
        bool isRedTurn;
        bool blackHuman;
        bool redHuman;

        OpenFileDialog openFile;

        PictureBox [,] boardControl;
        Button[] buttonControl;
        int [,] board;
        int[] log;
        Image blackFill;
        Image redFill;
        Image blankFill;
        Image redTurn, blackTurn;

        string redAIloc;
        string blackAIloc;
        int turnCount;
        int logTurnCount;
        public gameInterface()
        {
            InitializeComponent();

            openFile = new OpenFileDialog();
            openFile.Filter = "executable files (*.exe)|*.exe|All files (*.*)|*.*";
            openFile.FilterIndex = 1;


            blackHuman = true;
            redHuman = true;
            gameStarted = false;

            isRedTurn = true;

            boardControl = new PictureBox[7,6];
            buttonControl = new Button[7];

            redAIloc = "";
            blackAIloc = "";

            //This bit here is how to get the images from the resource handler
            Assembly _assembly;
            _assembly = Assembly.GetExecutingAssembly();

            Stream _imageStream = _assembly.GetManifestResourceStream("Connect_Four_CSharp.Images.filledBlack.png");
            blackFill = new Bitmap(_imageStream);

            _imageStream = _assembly.GetManifestResourceStream("Connect_Four_CSharp.Images.filledRed.png");
            redFill = new Bitmap(_imageStream);

            _imageStream = _assembly.GetManifestResourceStream("Connect_Four_CSharp.Images.redPlayer.png");
            redTurn = new Bitmap(_imageStream);

            _imageStream = _assembly.GetManifestResourceStream("Connect_Four_CSharp.Images.blackPlayer.png");
            blackTurn = new Bitmap(_imageStream);

            _imageStream = _assembly.GetManifestResourceStream("Connect_Four_CSharp.Images.open.png");
            blankFill = new Bitmap(_imageStream);

            //look at this variable in debug if you ever are unsure what to name the resources
            //string[] test;
            //test = _assembly.GetManifestResourceNames();

            


        }

        /// <summary>
        /// modifies the board by adding a piece
        /// </summary>
        /// <param name="isRed">is the player red?</param>
        /// <param name="pos">slot, from the left, to drop the piece</param>
        /// <returns>returns true if the move is legit</returns>
        public bool drop(bool isRed, int pos)
        {
            //bad move
            if (pos >= 7)
                return false;

            //go from the bottom
            bool fired = false;
            for (int i = 0; i < 6; i++)
            {
                if (board[pos,i] == 0)
                {
                    if (isRed)
                    {
                        board[pos, i] = 1;
                        boardControl[pos, i].BackgroundImage = redFill;

                    }
                    else
                    {
                        board[pos, i] = -1;
                        boardControl[pos, i].BackgroundImage = blackFill;

                    }
                    fired = true;
                    break;
                    
                }
            }
            if (logTurnCount == -1)
                logTurnCount = 0;
            if (turnCount != logTurnCount)
                turnCount = logTurnCount + 1;
            log[turnCount] = pos;
            logTurnCount = turnCount++;

            for (int i = turnCount; i < 42; i++)
                log[i] = -1;

            if (!fired)
            {
                //player tried to drop on a full row
                string temp = "";
                string temp2 = "";
                if (isRed)
                {
                    temp = "Red Player ";
                    temp2 = "Black Player ";
                }
                else
                {
                    temp = "Black Player ";
                    temp2 = "Red Player ";
                }
                MessageBox.Show(this, temp + "attempted to place on an invalid row.\n " + temp2 + "Is the Winner!", "Invalid Move", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return false;
            }
            else
            {
                if (board[pos,5] != 0)
                {
                    buttonControl[pos].Enabled = false;
                    //buttonControl[pos].BackColor = Color.Red;
                }
                else
                    buttonControl[pos].Enabled = true;
            }

            //find winners
            int result = findWinner();
            if (result == -1)
            {
                MessageBox.Show(this, "Black is the winner!", "Black wins!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return true;
            }
            else if (result == 1)
            {
                MessageBox.Show(this, "Red is the winner!", "Red wins!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return true;
            }


            //change turns
            isRedTurn = !isRedTurn;
            if (isRedTurn)
            {
                TurnIndicator.BackgroundImage = redTurn;
            }
            else
            {
                TurnIndicator.BackgroundImage = blackTurn;
            }

            //lock buttons if necissary
            bool pushable = false;
            pushable = (isRedTurn && redHuman) || (!isRedTurn && blackHuman);
            for (int i = 0; i < 7; i++)
            {
                if (board[i, 5] != 0)
                    buttonControl[i].Enabled = false;
                else
                    buttonControl[i].Enabled = pushable;
                
            }

            return fired;
        }
        public void logBackUp()
        {
            int value;
            if (logTurnCount < 0 || logTurnCount >= turnCount)
                return;



            value = log[logTurnCount];

            for (int i = 5; i > -1; i--)
            {
                if (board[value, i] != 0)
                {
                    board[value, i] = 0;
                    boardControl[value, i].BackgroundImage = blankFill;
                    isRedTurn = !isRedTurn;
                    if (TurnIndicator.BackgroundImage == blackTurn)
                        TurnIndicator.BackgroundImage = redTurn;
                    else
                        TurnIndicator.BackgroundImage = blackTurn;

                    break;
                }

            }
            logTurnCount--;

        }
        public void logFoward()
        {
            int value;

            if (logTurnCount < -1 || logTurnCount >= turnCount - 1)
                return;
            logTurnCount++;
            if (logTurnCount >= turnCount)
                logTurnCount = turnCount;

            value = log[logTurnCount];
            for (int i = 5; i >= -1; i--)
            {

                if (i == -1 || board[value, i] != 0)
                {

                    i++;
                    if (logTurnCount % 2 == 0)
                    {
                        board[value, i] = 1;
                        boardControl[value, i].BackgroundImage = redFill;
                    }
                    else
                    {
                        board[value, i] = -1;
                        boardControl[value, i].BackgroundImage = blackFill;
                    }
                    isRedTurn = !isRedTurn;
                    if (TurnIndicator.BackgroundImage == blackTurn)
                        TurnIndicator.BackgroundImage = redTurn;
                    else
                        TurnIndicator.BackgroundImage = blackTurn;

                    break;
                }


            }


        }


        private void Form1_Load(object sender, EventArgs e)
        {
            //gather up the button controls
            string cellFinder;
            for (int xdimm = 0; xdimm < 7; xdimm++)
            {
                cellFinder = "Drop" + xdimm.ToString();
                buttonControl[xdimm] = (Button)(this.Controls.Find(cellFinder, true)[0]);
            } 
    
            //...and this is how it's assigned
            //cell05.BackgroundImage = blackFill;
            
            
            Control[] temp;

            //gathering the controls into one place
            

            for (int ydimm = 0; ydimm < 6; ydimm++)
            {
                for (int xdimm = 0; xdimm < 7; xdimm++)
                {

                    cellFinder = "cell" + xdimm.ToString() + ydimm.ToString();
                    temp = this.Controls.Find(cellFinder, true);
                    boardControl[xdimm, ydimm] = (PictureBox)(temp[0]);

                }


            }
            resetGame();

        }

        /// <summary>
        /// Makes the game new again
        /// blanks the board visually and conecptually
        /// sets red player as first again
        /// </summary>
        private void resetGame()
        {
            //this little bit will change
            bool pushable = true;

            pushable = redHuman;

            board = new int[7, 6];
            for (int j = 0; j < 7; j++)
            {
                for (int i = 0; i < 6; i++)
                {
                    board[j, i] = 0;
                    boardControl[j, i].BackgroundImage = blankFill;
                    
                }

                buttonControl[j].Enabled = pushable;
              
            }
            log = new int[42];
            for (int i = 0; i < 42; i++)
            {
                log[i] = -1;
            }
            turnCount = 0;
            logTurnCount = -1;
            isRedTurn = true;
            TurnIndicator.BackgroundImage = redTurn;

        }

        private void Drop0_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 0);
        }

        private void Drop1_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 1);
        }

        private void Drop2_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 2);
        }

        private void Drop3_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 3);
        }

        private void Drop4_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 4);
        }

        private void Drop5_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 5);
        }

        private void Drop6_Click(object sender, EventArgs e)
        {
            drop(isRedTurn, 6);
        }

        private int findWinner()
        {
            int redsV = 0;
            
            int redsH = 0;
            int redsD = 0;
            int blacksV = 0;
            
            int blacksH = 0;
            int blacksD = 0;


            int[,] startsL = new int[6, 2] {
                                {0, 3},
                                {0, 4},
                                {0,5},
                                {1,5},
                                {2,5},
                                {3,5}};

            int[,] startsR = new int[6, 2] {
                                {6,3},
                                {6,4},
                                {6,5},
                                {5,5},
                                {4,5},
                                {3,5}};




            int lastH = 0;
            int lastV = 0;
            int lastD = 0;

            //search vertical
            for (int i = 0; i < 7; i++)
            {
                redsV = 0;
                blacksV = 0;
                for (int j = 0; j < 6; j++)
                {
                    if (board[i, j] != lastV)
                    {
                        redsV = 0;
                        blacksV = 0;
                        lastV = board[i, j];
                    }

                    if (board[i, j] == 1)
                    {
                        redsV++;
                    }
                    else if (board[i, j] == -1)
                    {
                        blacksV++;
                    }

                    if (blacksV >= 4 || redsV >= 4)
                    {
                        return lastV;
                    }

                }

            }

            //search horizontal
            for (int j = 0; j < 6; j++)
            {
                for (int i = 0; i < 7; i++)
                {
                    //count needs to be in a row, otherwise, it doesn't count
                    if (board[i, j] != lastH)
                    {
                        redsH = 0;
                        blacksH = 0;
                        lastH = board[i, j];
                    }

                    if (board[i, j] == 1)
                    {
                        redsH++;
                    }
                    else if (board[i, j] == -1)
                    {
                        blacksH++;
                    }

                    if (blacksH >= 4 || redsH >= 4)
                    {
                        return lastH;
                    }

                }

            }

            //diagnols are trickier, as they start at a weird place and end at a weird place
            //left to right botoom
            int disp = 0;
            for (int k = 0; k < startsL.Length / 2; k++)
            {
                disp = 0;
                redsD = 0;
                blacksD = 0;
                //while within bounds
                while (startsL[k, 0] + disp >= 0 && startsL[k, 0] + disp < 7 && startsL[k, 1] + disp >= 0 && startsL[k, 1] + disp < 6)
                {
                    //count needs to be in a row, otherwise, it doesn't count
                    if (board[startsL[k, 0] + disp, startsL[k, 1] + disp] != lastD)
                    {
                        redsD = 0;
                        blacksD = 0;
                        lastD = board[startsL[k, 0] + disp, startsL[k, 1] + disp];
                    }

                    if (board[startsL[k, 0] + disp, startsL[k, 1] + disp] == 1)
                    {
                        redsD++;
                    }
                    else if (board[startsL[k, 0] + disp, startsL[k, 1] + disp] == -1)
                    {
                        blacksD++;
                    }

                    if (blacksD >= 4 || redsD >= 4)
                    {
                        return lastD;
                    }
                    disp++;
                }
            }

            //right top to left bottom
            for (int k = 0; k < startsR.Length / 2; k++)
            {
                disp = 0;
                redsD = 0;
                blacksD = 0;
                //while within bounds
                while (startsR[k, 0] + disp >= 0 && startsR[k, 0] + disp < 7 && startsR[k, 1] + disp >= 0 && startsR[k, 1] + disp < 6)
                {
                    //count needs to be in a row, otherwise, it doesn't count
                    if (board[startsR[k, 0] + disp, startsR[k, 1] + disp] != lastD)
                    {
                        redsD = 0;
                        blacksD = 0;
                        lastD = board[startsR[k, 0] + disp, startsR[k, 1] + disp];
                    }

                    if (board[startsR[k, 0] + disp, startsR[k, 1] + disp] == 1)
                    {
                        redsD++;
                    }
                    else if (board[startsR[k, 0] + disp, startsR[k, 1] + disp] == -1)
                    {
                        blacksD++;
                    }

                    if (blacksD >= 4 || redsD >= 4)
                    {
                        return lastD;
                    }
                    disp--;
                }
            }



            return 0;
        }


        private void GameReset_Click(object sender, EventArgs e)
        {
            resetGame();
            GameStart.Enabled = true;
            BlackHum.Enabled = true;
            BlackComputer.Enabled = true;
            RedComputer.Enabled = true;
            RedHum.Enabled = true;
        }

        private void resetGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            resetGame();
            GameStart.Enabled = true;
            BlackHum.Enabled = true;
            BlackComputer.Enabled = true;
            RedComputer.Enabled = true;
            RedHum.Enabled = true;
        }

        private void RedComputer_Click(object sender, EventArgs e)
        {
            redHuman = false;
            RedState.Text = "Computer";
			//open dialogue box
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                redFile.Text = redAIloc = openFile.FileName;
            }
			   if ( redFile.Text == "" )
            {
                redHuman = true;
                RedState.Text = "Human";
            }
            
        }

        private void RedHum_Click(object sender, EventArgs e)
        {
            redHuman = true;
             RedState.Text = "Human";
        }

        private void BlackComputer_Click(object sender, EventArgs e)
        {
            blackHuman = false;
            BlackState.Text = "Computer";

            //open dialogue box
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                blackFile.Text = blackAIloc = openFile.FileName;
            }
			if (blackFile.Text == "")
            {
                blackHuman = true;
                BlackState.Text = "Human";
            }
        }

        private void BlackHum_Click(object sender, EventArgs e)
        {
            blackHuman = true;
            BlackState.Text = "Human";
        }

        private void GameStart_Click(object sender, EventArgs e)
        {
            GameStart.Enabled = false;
            gameStarted = true;

            BlackHum.Enabled = false;
            BlackComputer.Enabled = false;
            RedComputer.Enabled = false;
            RedHum.Enabled = false;
        }

        private void openLogFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
            String content = "";
            OpenFileDialog openFile = new OpenFileDialog();

            openFile.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            openFile.FilterIndex = 2;
            openFile.RestoreDirectory = true;

            if (openFile.ShowDialog() == DialogResult.OK)
            {
                if (openFile.FileName != "")
                {
                    resetGame();
                    content = File.ReadAllText(openFile.FileName);
                    for (int i = 0; i < 42; i++)
                    {
                        log[i] = -1;
                    }
                    int index = 0;
                    foreach (var s in content.Split(' '))
                    {
                        int num;
                        if (int.TryParse(s, out num))
                        {
                            log[index] = num;
                            index++;
                        }
                    }
                    turnCount = index;
                }
                else
                {
                    MessageBox.Show("Select a file");
                }
            }
        }

 
        private void saveLogFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String content = "";
            for (int i = 0; i < 42; i++)
            {
                if (log[i] == -1)
                    break;
                content += log[i].ToString() + " ";
            }

            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if (saveFileDialog1.FileName != "")
                {
                    File.WriteAllText(saveFileDialog1.FileName, content);
                }
                else
                {
                    MessageBox.Show("Select a file");
                }
            }
            
        }

        private void forwardLogToolStripMenuItem_Click(object sender, EventArgs e)
        {
            logFoward();
        }

        private void backLogToolStripMenuItem_Click(object sender, EventArgs e)
        {
            logBackUp();
        }

        private void backButton_Click(object sender, EventArgs e)
        {
            logBackUp();
        }

        private void forwardButton_Click(object sender, EventArgs e)
        {
            logFoward();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

     







    }
}
