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



namespace Connect_Four_CSharp
{
    public partial class gameInterface : Form
    {
        bool isRedTurn;
        bool blackHuman;
        bool redHuman;

        PictureBox [,] boardControl;
        Button[] buttonControl;
        int [,] board;
        Image blackFill;
        Image redFill;
        Image blankFill;
        Image redTurn, blackTurn;

        public gameInterface()
        {
            InitializeComponent();

            blackHuman = true;
            redHuman = true;

            isRedTurn = true;

            boardControl = new PictureBox[7,6];
            buttonControl = new Button[7];

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
                buttonControl[i].Enabled = pushable;
            }

            return fired;
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
            int [] redsH = new int[6];
            int blacksV = 0;
            int [] blacksH = new int [6];

            int lastH = 0;
            int lastV = 0;

            for (int i = 0; i < 7; i++)
            {
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

            return 0;
        }


        private void button5_Click(object sender, EventArgs e)
        {
            resetGame();
        }

        private void resetGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            resetGame();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            // DERP!
        }

    }
}
