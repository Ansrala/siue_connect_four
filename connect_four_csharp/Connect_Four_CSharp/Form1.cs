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
    public partial class Form1 : Form
    {
        PictureBox [,] boardControl;
        Image blackFill;
        Image redFill;
        Image redTurn, blackTurn;

        public Form1()
        {
            InitializeComponent();

            boardControl = new PictureBox[7,6];

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

            //look at this variable in debug if you ever are unsure what to name the resources
            //string[] test;
            //test = _assembly.GetManifestResourceNames();

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {





            
    
            //...and this is how it's assigned
            //cell05.BackgroundImage = blackFill;
            
            
            Control[] temp;

            //gathering the controls into one place
            string cellFinder;

            for (int ydimm = 0; ydimm < 6; ydimm++)
            {
                for (int xdimm = 0; xdimm < 7; xdimm++)
                {

                    cellFinder = "cell" + xdimm.ToString() + ydimm.ToString();
                    temp = this.Controls.Find(cellFinder, true);
                    boardControl[xdimm, ydimm] = (PictureBox)(temp[0]);

                }


            }

        }




    }
}
