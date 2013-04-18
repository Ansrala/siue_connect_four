#pragma once

namespace connect_four {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox1;










































	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button51;
	private: System::Windows::Forms::Button^  button50;
	private: System::Windows::Forms::Button^  button49;
	private: System::Windows::Forms::Button^  button48;
	private: System::Windows::Forms::Button^  button47;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  openLogFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveLogFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  startGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resetGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fowardLogToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  backLogToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  computerTImeLimitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  secondsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  secondsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  secondsToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  minuteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  noLimitToolStripMenuItem;
	private: System::Windows::Forms::Button^  drop1;
	private: System::Windows::Forms::Button^  drop2;
	private: System::Windows::Forms::Button^  drop3;
	private: System::Windows::Forms::Button^  drop4;
	private: System::Windows::Forms::Button^  drop5;
	private: System::Windows::Forms::Button^  drop6;
	private: System::Windows::Forms::Button^  drop7;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openLogFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveLogFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fowardLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->computerTImeLimitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->secondsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->secondsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->secondsToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minuteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->noLimitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drop1 = (gcnew System::Windows::Forms::Button());
			this->drop2 = (gcnew System::Windows::Forms::Button());
			this->drop3 = (gcnew System::Windows::Forms::Button());
			this->drop4 = (gcnew System::Windows::Forms::Button());
			this->drop5 = (gcnew System::Windows::Forms::Button());
			this->drop6 = (gcnew System::Windows::Forms::Button());
			this->drop7 = (gcnew System::Windows::Forms::Button());
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(158, 17);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Human";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 17);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Computer";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(158, 17);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Human";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(22, 17);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(98, 30);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Computer";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(359, 67);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Size = System::Drawing::Size(470, 454);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(22, 62);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(156, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Show Red Player\'s Console";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(22, 63);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(163, 17);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Show Black Player\'s Console";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Location = System::Drawing::Point(9, 50);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox2->Size = System::Drawing::Size(309, 161);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Red";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &Form1::groupBox2_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->checkBox2);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(9, 243);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox3->Size = System::Drawing::Size(308, 164);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Black";
			this->groupBox3->Enter += gcnew System::EventHandler(this, &Form1::groupBox3_Enter);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->button51);
			this->groupBox4->Controls->Add(this->button50);
			this->groupBox4->Controls->Add(this->button49);
			this->groupBox4->Controls->Add(this->button48);
			this->groupBox4->Controls->Add(this->button47);
			this->groupBox4->Location = System::Drawing::Point(9, 428);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox4->Size = System::Drawing::Size(308, 145);
			this->groupBox4->TabIndex = 9;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Control";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(158, 52);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 43;
			this->label1->Text = L"Current Player";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// button51
			// 
			this->button51->Location = System::Drawing::Point(158, 68);
			this->button51->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(56, 61);
			this->button51->TabIndex = 42;
			this->button51->UseVisualStyleBackColor = true;
			// 
			// button50
			// 
			this->button50->Location = System::Drawing::Point(22, 98);
			this->button50->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(98, 30);
			this->button50->TabIndex = 10;
			this->button50->Text = L"Back Log";
			this->button50->UseVisualStyleBackColor = true;
			// 
			// button49
			// 
			this->button49->Location = System::Drawing::Point(22, 63);
			this->button49->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(98, 30);
			this->button49->TabIndex = 9;
			this->button49->Text = L"Forward Log";
			this->button49->UseVisualStyleBackColor = true;
			// 
			// button48
			// 
			this->button48->Location = System::Drawing::Point(158, 17);
			this->button48->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(98, 30);
			this->button48->TabIndex = 8;
			this->button48->Text = L"Reset Game";
			this->button48->UseVisualStyleBackColor = true;
			// 
			// button47
			// 
			this->button47->Location = System::Drawing::Point(22, 17);
			this->button47->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(98, 30);
			this->button47->TabIndex = 7;
			this->button47->Text = L"Start Game";
			this->button47->UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
				this->gameToolStripMenuItem, this->computerTImeLimitToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(888, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openLogFileToolStripMenuItem, 
				this->saveLogFileToolStripMenuItem, this->exitToolStripMenuItem});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
			this->toolStripMenuItem1->Text = L"File";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			// 
			// openLogFileToolStripMenuItem
			// 
			this->openLogFileToolStripMenuItem->Name = L"openLogFileToolStripMenuItem";
			this->openLogFileToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->openLogFileToolStripMenuItem->Text = L"Open Log File";
			// 
			// saveLogFileToolStripMenuItem
			// 
			this->saveLogFileToolStripMenuItem->Name = L"saveLogFileToolStripMenuItem";
			this->saveLogFileToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->saveLogFileToolStripMenuItem->Text = L"Save Log File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->startGameToolStripMenuItem, 
				this->resetGameToolStripMenuItem, this->fowardLogToolStripMenuItem, this->backLogToolStripMenuItem, this->aboutToolStripMenuItem});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// startGameToolStripMenuItem
			// 
			this->startGameToolStripMenuItem->Name = L"startGameToolStripMenuItem";
			this->startGameToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->startGameToolStripMenuItem->Text = L"Start Game";
			// 
			// resetGameToolStripMenuItem
			// 
			this->resetGameToolStripMenuItem->Name = L"resetGameToolStripMenuItem";
			this->resetGameToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->resetGameToolStripMenuItem->Text = L"Reset Game";
			// 
			// fowardLogToolStripMenuItem
			// 
			this->fowardLogToolStripMenuItem->Name = L"fowardLogToolStripMenuItem";
			this->fowardLogToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->fowardLogToolStripMenuItem->Text = L"Foward Log";
			// 
			// backLogToolStripMenuItem
			// 
			this->backLogToolStripMenuItem->Name = L"backLogToolStripMenuItem";
			this->backLogToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->backLogToolStripMenuItem->Text = L"Back Log";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// computerTImeLimitToolStripMenuItem
			// 
			this->computerTImeLimitToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->secondsToolStripMenuItem, 
				this->secondsToolStripMenuItem1, this->secondsToolStripMenuItem2, this->minuteToolStripMenuItem, this->noLimitToolStripMenuItem});
			this->computerTImeLimitToolStripMenuItem->Name = L"computerTImeLimitToolStripMenuItem";
			this->computerTImeLimitToolStripMenuItem->Size = System::Drawing::Size(133, 20);
			this->computerTImeLimitToolStripMenuItem->Text = L"Computer Time Limit";
			// 
			// secondsToolStripMenuItem
			// 
			this->secondsToolStripMenuItem->Checked = true;
			this->secondsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->secondsToolStripMenuItem->Name = L"secondsToolStripMenuItem";
			this->secondsToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->secondsToolStripMenuItem->Text = L"5 Seconds";
			// 
			// secondsToolStripMenuItem1
			// 
			this->secondsToolStripMenuItem1->Name = L"secondsToolStripMenuItem1";
			this->secondsToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->secondsToolStripMenuItem1->Text = L"10 Seconds";
			// 
			// secondsToolStripMenuItem2
			// 
			this->secondsToolStripMenuItem2->Name = L"secondsToolStripMenuItem2";
			this->secondsToolStripMenuItem2->Size = System::Drawing::Size(152, 22);
			this->secondsToolStripMenuItem2->Text = L"20 Seconds";
			// 
			// minuteToolStripMenuItem
			// 
			this->minuteToolStripMenuItem->Name = L"minuteToolStripMenuItem";
			this->minuteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->minuteToolStripMenuItem->Text = L"1 Minute";
			// 
			// noLimitToolStripMenuItem
			// 
			this->noLimitToolStripMenuItem->Name = L"noLimitToolStripMenuItem";
			this->noLimitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->noLimitToolStripMenuItem->Text = L"No Limit";
			// 
			// drop1
			// 
			this->drop1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop1->Location = System::Drawing::Point(359, 37);
			this->drop1->Name = L"drop1";
			this->drop1->Size = System::Drawing::Size(62, 25);
			this->drop1->TabIndex = 11;
			this->drop1->Text = L"V";
			this->drop1->UseVisualStyleBackColor = true;
			// 
			// drop2
			// 
			this->drop2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop2->Location = System::Drawing::Point(427, 37);
			this->drop2->Name = L"drop2";
			this->drop2->Size = System::Drawing::Size(62, 25);
			this->drop2->TabIndex = 12;
			this->drop2->Text = L"V";
			this->drop2->UseVisualStyleBackColor = true;
			// 
			// drop3
			// 
			this->drop3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop3->Location = System::Drawing::Point(495, 37);
			this->drop3->Name = L"drop3";
			this->drop3->Size = System::Drawing::Size(62, 25);
			this->drop3->TabIndex = 13;
			this->drop3->Text = L"V";
			this->drop3->UseVisualStyleBackColor = true;
			this->drop3->Click += gcnew System::EventHandler(this, &Form1::drop3_Click);
			// 
			// drop4
			// 
			this->drop4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop4->Location = System::Drawing::Point(563, 37);
			this->drop4->Name = L"drop4";
			this->drop4->Size = System::Drawing::Size(62, 25);
			this->drop4->TabIndex = 14;
			this->drop4->Text = L"V";
			this->drop4->UseVisualStyleBackColor = true;
			// 
			// drop5
			// 
			this->drop5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop5->Location = System::Drawing::Point(631, 37);
			this->drop5->Name = L"drop5";
			this->drop5->Size = System::Drawing::Size(62, 25);
			this->drop5->TabIndex = 15;
			this->drop5->Text = L"V";
			this->drop5->UseVisualStyleBackColor = true;
			// 
			// drop6
			// 
			this->drop6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop6->Location = System::Drawing::Point(699, 37);
			this->drop6->Name = L"drop6";
			this->drop6->Size = System::Drawing::Size(62, 25);
			this->drop6->TabIndex = 16;
			this->drop6->Text = L"V";
			this->drop6->UseVisualStyleBackColor = true;
			// 
			// drop7
			// 
			this->drop7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->drop7->Location = System::Drawing::Point(767, 37);
			this->drop7->Name = L"drop7";
			this->drop7->Size = System::Drawing::Size(62, 25);
			this->drop7->TabIndex = 17;
			this->drop7->Text = L"V";
			this->drop7->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 583);
			this->Controls->Add(this->drop7);
			this->Controls->Add(this->drop6);
			this->Controls->Add(this->drop5);
			this->Controls->Add(this->drop4);
			this->Controls->Add(this->drop3);
			this->Controls->Add(this->drop2);
			this->Controls->Add(this->drop1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Form1";
			this->Text = L"Connect 4 .... OF DOOOM";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void drop3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

