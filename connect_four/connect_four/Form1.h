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
	private: System::Windows::Forms::Button^  button40;
	private: System::Windows::Forms::Button^  button41;
	private: System::Windows::Forms::Button^  button42;
	private: System::Windows::Forms::Button^  button43;
	private: System::Windows::Forms::Button^  button44;
	private: System::Windows::Forms::Button^  button45;
	private: System::Windows::Forms::Button^  button46;
	private: System::Windows::Forms::Button^  button33;
	private: System::Windows::Forms::Button^  button34;
	private: System::Windows::Forms::Button^  button35;
	private: System::Windows::Forms::Button^  button36;
	private: System::Windows::Forms::Button^  button37;
	private: System::Windows::Forms::Button^  button38;
	private: System::Windows::Forms::Button^  button39;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button29;
	private: System::Windows::Forms::Button^  button30;
	private: System::Windows::Forms::Button^  button31;
	private: System::Windows::Forms::Button^  button32;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(215, 54);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Human";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 54);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Computer";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(211, 24);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Human";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(29, 24);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 37);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Computer";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button40);
			this->groupBox1->Controls->Add(this->button41);
			this->groupBox1->Controls->Add(this->button42);
			this->groupBox1->Controls->Add(this->button43);
			this->groupBox1->Controls->Add(this->button44);
			this->groupBox1->Controls->Add(this->button45);
			this->groupBox1->Controls->Add(this->button46);
			this->groupBox1->Controls->Add(this->button33);
			this->groupBox1->Controls->Add(this->button34);
			this->groupBox1->Controls->Add(this->button35);
			this->groupBox1->Controls->Add(this->button36);
			this->groupBox1->Controls->Add(this->button37);
			this->groupBox1->Controls->Add(this->button38);
			this->groupBox1->Controls->Add(this->button39);
			this->groupBox1->Controls->Add(this->button26);
			this->groupBox1->Controls->Add(this->button27);
			this->groupBox1->Controls->Add(this->button28);
			this->groupBox1->Controls->Add(this->button29);
			this->groupBox1->Controls->Add(this->button30);
			this->groupBox1->Controls->Add(this->button31);
			this->groupBox1->Controls->Add(this->button32);
			this->groupBox1->Controls->Add(this->button19);
			this->groupBox1->Controls->Add(this->button20);
			this->groupBox1->Controls->Add(this->button21);
			this->groupBox1->Controls->Add(this->button22);
			this->groupBox1->Controls->Add(this->button23);
			this->groupBox1->Controls->Add(this->button24);
			this->groupBox1->Controls->Add(this->button25);
			this->groupBox1->Controls->Add(this->button12);
			this->groupBox1->Controls->Add(this->button13);
			this->groupBox1->Controls->Add(this->button14);
			this->groupBox1->Controls->Add(this->button15);
			this->groupBox1->Controls->Add(this->button16);
			this->groupBox1->Controls->Add(this->button17);
			this->groupBox1->Controls->Add(this->button18);
			this->groupBox1->Controls->Add(this->button11);
			this->groupBox1->Controls->Add(this->button10);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Location = System::Drawing::Point(610, 80);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(562, 523);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(0, 0);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 75);
			this->button5->TabIndex = 0;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(81, 0);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 75);
			this->button6->TabIndex = 1;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(162, 0);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 75);
			this->button7->TabIndex = 2;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(243, 0);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 75);
			this->button8->TabIndex = 3;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(324, 0);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 75);
			this->button9->TabIndex = 4;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(405, 0);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 75);
			this->button10->TabIndex = 5;
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(486, 0);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 75);
			this->button11->TabIndex = 6;
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(486, 81);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 75);
			this->button12->TabIndex = 13;
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(405, 81);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 75);
			this->button13->TabIndex = 12;
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(324, 81);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 75);
			this->button14->TabIndex = 11;
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(243, 81);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(75, 75);
			this->button15->TabIndex = 10;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(162, 81);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(75, 75);
			this->button16->TabIndex = 9;
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(81, 81);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 75);
			this->button17->TabIndex = 8;
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(0, 81);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(75, 75);
			this->button18->TabIndex = 7;
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(486, 162);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(75, 75);
			this->button19->TabIndex = 20;
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(405, 162);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(75, 75);
			this->button20->TabIndex = 19;
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(324, 162);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(75, 75);
			this->button21->TabIndex = 18;
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(243, 162);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(75, 75);
			this->button22->TabIndex = 17;
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(162, 162);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(75, 75);
			this->button23->TabIndex = 16;
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(81, 162);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(75, 75);
			this->button24->TabIndex = 15;
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(0, 162);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(75, 75);
			this->button25->TabIndex = 14;
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(486, 243);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(75, 75);
			this->button26->TabIndex = 27;
			this->button26->UseVisualStyleBackColor = true;
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(405, 243);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(75, 75);
			this->button27->TabIndex = 26;
			this->button27->UseVisualStyleBackColor = true;
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(324, 243);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(75, 75);
			this->button28->TabIndex = 25;
			this->button28->UseVisualStyleBackColor = true;
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(243, 243);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(75, 75);
			this->button29->TabIndex = 24;
			this->button29->UseVisualStyleBackColor = true;
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(162, 243);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(75, 75);
			this->button30->TabIndex = 23;
			this->button30->UseVisualStyleBackColor = true;
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(81, 243);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(75, 75);
			this->button31->TabIndex = 22;
			this->button31->UseVisualStyleBackColor = true;
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(0, 243);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(75, 75);
			this->button32->TabIndex = 21;
			this->button32->UseVisualStyleBackColor = true;
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(486, 324);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(75, 75);
			this->button33->TabIndex = 34;
			this->button33->UseVisualStyleBackColor = true;
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(405, 324);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(75, 75);
			this->button34->TabIndex = 33;
			this->button34->UseVisualStyleBackColor = true;
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(324, 324);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(75, 75);
			this->button35->TabIndex = 32;
			this->button35->UseVisualStyleBackColor = true;
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(243, 324);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(75, 75);
			this->button36->TabIndex = 31;
			this->button36->UseVisualStyleBackColor = true;
			// 
			// button37
			// 
			this->button37->Location = System::Drawing::Point(162, 324);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(75, 75);
			this->button37->TabIndex = 30;
			this->button37->UseVisualStyleBackColor = true;
			// 
			// button38
			// 
			this->button38->Location = System::Drawing::Point(81, 324);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(75, 75);
			this->button38->TabIndex = 29;
			this->button38->UseVisualStyleBackColor = true;
			// 
			// button39
			// 
			this->button39->Location = System::Drawing::Point(0, 324);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(75, 75);
			this->button39->TabIndex = 28;
			this->button39->UseVisualStyleBackColor = true;
			// 
			// button40
			// 
			this->button40->Location = System::Drawing::Point(486, 405);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(75, 75);
			this->button40->TabIndex = 41;
			this->button40->UseVisualStyleBackColor = true;
			// 
			// button41
			// 
			this->button41->Location = System::Drawing::Point(405, 405);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(75, 75);
			this->button41->TabIndex = 40;
			this->button41->UseVisualStyleBackColor = true;
			// 
			// button42
			// 
			this->button42->Location = System::Drawing::Point(324, 405);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(75, 75);
			this->button42->TabIndex = 39;
			this->button42->UseVisualStyleBackColor = true;
			// 
			// button43
			// 
			this->button43->Location = System::Drawing::Point(243, 405);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(75, 75);
			this->button43->TabIndex = 38;
			this->button43->UseVisualStyleBackColor = true;
			// 
			// button44
			// 
			this->button44->Location = System::Drawing::Point(162, 405);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(75, 75);
			this->button44->TabIndex = 37;
			this->button44->UseVisualStyleBackColor = true;
			// 
			// button45
			// 
			this->button45->Location = System::Drawing::Point(81, 405);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(75, 75);
			this->button45->TabIndex = 36;
			this->button45->UseVisualStyleBackColor = true;
			// 
			// button46
			// 
			this->button46->Location = System::Drawing::Point(0, 405);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(75, 75);
			this->button46->TabIndex = 35;
			this->button46->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(33, 99);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(203, 21);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Show Red Player\'s Console";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(29, 67);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(211, 21);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Show Black Player\'s Console";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Location = System::Drawing::Point(12, 62);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(412, 198);
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
			this->groupBox3->Location = System::Drawing::Point(16, 299);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(407, 202);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Black";
			this->groupBox3->Enter += gcnew System::EventHandler(this, &Form1::groupBox3_Enter);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1401, 615);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

