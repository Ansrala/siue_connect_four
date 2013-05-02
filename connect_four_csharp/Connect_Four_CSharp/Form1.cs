﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.IO;
using System.Reflection;
using System.Diagnostics;



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
        int[] counts;
        int [,] board;
        int[] log;
        Image blackFill;
        Image redFill;
        Image blankFill;
        Image redTurn, blackTurn;

        Stopwatch timer = new Stopwatch();
        int maxTime = 5000;

        
        int turnCount;
        int logTurnCount;
        ProcessStartInfo redStartInfo;
        ProcessStartInfo blackStartInfo;
        public gameInterface()
        {
            InitializeComponent();
            openFile = new OpenFileDialog();
            openFile.Filter = "executable files (*.exe)|*.exe";
            openFile.FilterIndex = 1;


            blackHuman = true;
            redHuman = true;
            gameStarted = false;

            isRedTurn = true;

            boardControl = new PictureBox[7,6];
            buttonControl = new Button[7];
        
            redStartInfo = new ProcessStartInfo();
            redStartInfo.FileName = "";
            redStartInfo.RedirectStandardError = false;
            redStartInfo.RedirectStandardOutput = false;
            redStartInfo.UseShellExecute = false;
            redStartInfo.CreateNoWindow = true;
            blackStartInfo = new ProcessStartInfo();
            blackStartInfo.FileName = "";
            blackStartInfo.RedirectStandardError = false;
            blackStartInfo.RedirectStandardOutput = false;
            blackStartInfo.UseShellExecute = false;
            blackStartInfo.CreateNoWindow = true;

   
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
        public bool drop(int pos)
        {
            //bad move
            if (pos >= 7)
            {
                gameStarted = false;
                return false;
            }

            //go from the bottom
            bool fired = false;
            for (int i = 0; i < 6; i++)
            {
                if (board[pos,i] == 0)
                {
                    if (isRedTurn)
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
            

                      
            if (!fired)
            {
                //player tried to drop on a full row
                string temp = "";
                string temp2 = "";
                if (isRedTurn)
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
            
            for( int i = 0; i < 7; i++)
            {

                if (board[i,5] != 0)
                {
                    buttonControl[i].Enabled = false;
                    //buttonControl[pos].BackColor = Color.Red;
                }
            }

            //find winners
            int result = findWinner();




            if (result == -1)
            {
                gameStarted = false;
                MessageBox.Show(this, "Black is the winner!", "Black wins!", MessageBoxButtons.OK, MessageBoxIcon.Information);

            }
            else if (result == 1)
            {
                gameStarted = false;
                MessageBox.Show(this, "Red is the winner!", "Red wins!", MessageBoxButtons.OK, MessageBoxIcon.Information);

            }
            else if (result == 3)
            {
                gameStarted = false;
                MessageBox.Show(this, "EVERYONE LOSES", "Tie!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
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
            bool pushable;
            pushable = ((isRedTurn && redHuman) || (!isRedTurn && blackHuman)) && (result == 0);
            for (int i = 0; i < 7; i++)
            {
                if (board[pos, 5] == 0)
                    buttonControl[i].Enabled = pushable;
            }



            this.Update();

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

            for (int i = 0; i < 7; i++)
            {

                if (board[i, 5] != 0)
                {
                    buttonControl[i].Enabled = false;
                    //buttonControl[pos].BackColor = Color.Red;
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

            for (int i = 0; i < 7; i++)
            {

                if (board[i, 5] != 0)
                {
                    buttonControl[i].Enabled = false;
                    //buttonControl[pos].BackColor = Color.Red;
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

            board = new int[7, 6];
            for (int j = 0; j < 7; j++)
            {
                for (int i = 0; i < 6; i++)
                {
                    board[j, i] = 0;
                    boardControl[j, i].BackgroundImage = blankFill;
                    
                }

                buttonControl[j].Enabled = false;
                
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

            GameStart.Enabled = true;
            startGameToolStripMenuItem.Enabled = true;
            BlackHum.Enabled = true;
            BlackComputer.Enabled = true;
            RedComputer.Enabled = true;
            RedHum.Enabled = true;

        }

        private void Drop0_Click(object sender, EventArgs e)
        {
            if (drop(0))
            {
                nextTurn();
            }
        }

        private void Drop1_Click(object sender, EventArgs e)
        {
            if (drop(1))
            {
                nextTurn();
            }
        }

        private void Drop2_Click(object sender, EventArgs e)
        {
            if (drop(2))
            {
                nextTurn();
            }
        }

        private void Drop3_Click(object sender, EventArgs e)
        {
            if (drop(3))
            {
                nextTurn();
            }
        }

        private void Drop4_Click(object sender, EventArgs e)
        {
            if (drop(4))
            {
                nextTurn();
            }
        }

        private void Drop5_Click(object sender, EventArgs e)
        {
            if (drop(5))
            {
                nextTurn();
            }
        }

        private void Drop6_Click(object sender, EventArgs e)
        {
            if (drop(6))
            {
                nextTurn();
            }
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
                        gameStarted = false;
                        return lastV;
                    }

                }

            }

            //search horizontal
            for (int j = 0; j < 6; j++)
            {
                redsH = 0;
                blacksH = 0;
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
                        gameStarted = false;
                        return lastH;
                    }

                }

            }

            //diagnols are trickier, as they start at a weird place and end at a weird place
            //left top to right botoom
            int disp = 0;
            for (int k = 0; k < startsL.Length / 2; k++)
            {
                disp = 0;
                redsD = 0;
                blacksD = 0;
                //while within bounds
                while (startsL[k, 0] + disp >= 0 && startsL[k, 0] + disp < 7 && startsL[k, 1] - disp >= 0 && startsL[k, 1] - disp < 6)
                {
                    //count needs to be in a row, otherwise, it doesn't count
                    if (board[startsL[k, 0] + disp, startsL[k, 1] - disp] != lastD)
                    {
                        redsD = 0;
                        blacksD = 0;
                        lastD = board[startsL[k, 0] + disp, startsL[k, 1] - disp];
                    }

                    if (board[startsL[k, 0] + disp, startsL[k, 1] - disp] == 1)
                    {
                        redsD++;
                    }
                    else if (board[startsL[k, 0] + disp, startsL[k, 1] - disp] == -1)
                    {
                        blacksD++;
                    }

                    if (blacksD >= 4 || redsD >= 4)
                    {
                        gameStarted = false;
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
                        gameStarted = false;
                        return lastD;
                    }
                    disp--;
                }
            }


            //tie check
            int tops = 0;
            for (int k = 0; k < 7; k++)
            {
                if (board[k, 5] != 0)
                {
                    tops++;
                }
            }
            if (tops == 7)
                return 3;



            return 0;
        }

        private void nextTurn()
        {
            //call AI turn
            if (((isRedTurn) && (!redHuman)) || ((!isRedTurn) && (!blackHuman)) && gameStarted)
            {
                for (int i = 0; i < 7; i++)
                {
                    buttonControl[i].Enabled = false;
                }

                aiTurn();
            }
        }

        private void aiTurn()
        {
            if (timer.IsRunning)
            {
                timer.Stop();
            }

            string folder;
                
            if(isRedTurn)
            {
               redStartInfo.WorkingDirectory= folder = redStartInfo.FileName.Substring(0, redStartInfo.FileName.LastIndexOf('\\')+1);
            }
            else
            {
                blackStartInfo.WorkingDirectory = folder = blackStartInfo.FileName.Substring(0, blackStartInfo.FileName.LastIndexOf('\\') + 1);
            }

            string[] boardArray = new string[6];

            for (int i = 0; i < 6; i++)
            {
                boardArray[i] = "";
                for (int j = 0; j < 7; j++)
                {
                    if (board[j, 5-i] == -1)
                    {
                        if (isRedTurn)
                        {
                            boardArray[i] += "-";
                        }
                        else
                        {
                            boardArray[i] += "+";
                        }
                    }
                    else if (board[j, 5-i] == 1)
                    {
                        if (isRedTurn)
                        {
                            boardArray[i] += "+";
                        }
                        else
                        {
                            boardArray[i] += "-";
                        }
                    }
                    else
                    {
                        boardArray[i] += ".";   
                    }
                }
            }

            string path = folder + "board.txt";

            File.WriteAllLines( path, boardArray );

            Process processTemp = new Process();
            if (isRedTurn)
            {
                processTemp.StartInfo = redStartInfo;
            }
            else
            {
                processTemp.StartInfo = blackStartInfo;  
            }

            try
            {
                processTemp.Start();
                timer.Start();
                string move = folder + "move.txt";
                bool cont = true;
                while (cont)
                {
                    if (timer.Elapsed.TotalMilliseconds >= maxTime)
                    {
                        //To-Do: Time expired, ask to continue?
                        cont = false;
                        processTemp.Close();
                        break;
                    }

                    if (File.Exists(move))
                    {
                        processTemp.Close();
                        break;
                    }
                }

                timer.Reset();
                timer.Start();

                while (timer.Elapsed.TotalMilliseconds <= 200)
                {
                }

                timer.Reset();

                if (File.Exists(move))
                {
                    string result = File.ReadAllText(move);
                    int pos;
                    int.TryParse(result, out pos);
                    drop(pos);
                    File.Delete(move);
                    if(gameStarted)
                        nextTurn();
                }
                else
                {
                    //To-Do: AI should lose here!
                }
            }
            catch (Exception e)
            {
                throw;
                //To-Do: AI should lose here!
            }
        }

        private void GameReset_Click(object sender, EventArgs e)
        {
            resetGame();
            
        }

        private void resetGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            resetGame();
        }

        private void RedComputer_Click(object sender, EventArgs e)
        {
            redHuman = false;
            RedState.Text = "Computer";

            //open dialogue box
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                redFile.Text = redStartInfo.FileName = openFile.FileName;
            }

            if (redStartInfo.FileName == "")
            {
                redHuman = true;
                RedState.Text = "Human";
            }
            resetGame();
        }

        private void RedHum_Click(object sender, EventArgs e)
        {
            redHuman = true;
             RedState.Text = "Human";
             resetGame();
        }

        private void BlackComputer_Click(object sender, EventArgs e)
        {
            blackHuman = false;
            BlackState.Text = "Computer";

            //open dialogue box
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                blackFile.Text = blackStartInfo.FileName = openFile.FileName;
            }

            if (blackStartInfo.FileName == "")
            {
                blackHuman = true;
                BlackState.Text = "Human";
            }
            resetGame();
        }

        private void BlackHum_Click(object sender, EventArgs e)
        {
            blackHuman = true;
            BlackState.Text = "Human";
            resetGame();
        }

        private void GameStart_Click(object sender, EventArgs e)
        {
            starGame();
        }
        private void starGame()
        {
            GameStart.Enabled = false;
            startGameToolStripMenuItem.Enabled = false;
            gameStarted = true;

            BlackHum.Enabled = false;
            BlackComputer.Enabled = false;
            RedComputer.Enabled = false;
            RedHum.Enabled = false;

            for (int i = 0; i < 7; i++)
            {
                buttonControl[i].Enabled = redHuman;
            }

            if (RedState.Text == "Computer")
            {
                aiTurn();
            }
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

        private void redCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (redCheckBox.Checked == true)
            {
                redStartInfo.CreateNoWindow = false;
        //        redStartInfo.UseShellExecute = true;
            }
            else
            {
                redStartInfo.CreateNoWindow = true;
        //        redStartInfo.UseShellExecute = false;
            }
        }

        private void blackCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (blackCheckBox.Checked == true)
            {
                blackStartInfo.CreateNoWindow = false;
           //     blackStartInfo.UseShellExecute = true;
            }
            else
            {
                blackStartInfo.CreateNoWindow = true;
           //     blackStartInfo.UseShellExecute = false;
            }
        }

        private void secondsToolStrip5SecondItem_Click(object sender, EventArgs e)
        {
            maxTime = 5000;
            secondsToolStrip5SecondItem.Checked = true;
            secondsToolStrip10SeconItem.Checked = false;
            secondsToolStrip20SecondItem.Checked = false;
            minuteToolStrip1MinItem.Checked = false;
            noLimitToolStripNoLimiteItem.Checked = false;
        }

        private void secondsToolStrip10SeconItem_Click(object sender, EventArgs e)
        {
            maxTime = 10000;
            secondsToolStrip5SecondItem.Checked = false;
            secondsToolStrip10SeconItem.Checked = true;
            secondsToolStrip20SecondItem.Checked = false;
            minuteToolStrip1MinItem.Checked = false;
            noLimitToolStripNoLimiteItem.Checked = false;
        }

        private void secondsToolStrip20SecondItem_Click(object sender, EventArgs e)
        {
            maxTime = 20000;
            secondsToolStrip5SecondItem.Checked = false;
            secondsToolStrip10SeconItem.Checked = false;
            secondsToolStrip20SecondItem.Checked = true;
            minuteToolStrip1MinItem.Checked = false;
            noLimitToolStripNoLimiteItem.Checked = false;
        }

        private void minuteToolStrip1MinItem_Click(object sender, EventArgs e)
        {
            maxTime = 60000;
            secondsToolStrip5SecondItem.Checked = false;
            secondsToolStrip10SeconItem.Checked = false;
            secondsToolStrip20SecondItem.Checked = false;
            minuteToolStrip1MinItem.Checked = true;
            noLimitToolStripNoLimiteItem.Checked = false;
        }

        private void noLimitToolStripNoLimiteItem_Click(object sender, EventArgs e)
        {
            maxTime = 1000000000;
            secondsToolStrip5SecondItem.Checked = false;
            secondsToolStrip10SeconItem.Checked = false;
            secondsToolStrip20SecondItem.Checked = false;
            minuteToolStrip1MinItem.Checked = false;
            noLimitToolStripNoLimiteItem.Checked = true;
        }

        private void startGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            starGame();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(this, "This interface was made by:\n \tWestin Breger\n\tJason Mitchell\n\tMaster Joe Moore, Esquire", "Credits", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }    
    }
}
