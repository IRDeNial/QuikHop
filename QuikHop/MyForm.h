#pragma once

using namespace std;

namespace QuikHop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace Resources;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

    private: System::Windows::Forms::Button^  button_initialize;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::TabControl^  tabControl1;
    private: System::Windows::Forms::TabPage^  tabPage3;
    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::TabPage^  tabPage4;

    private: System::Windows::Forms::GroupBox^  groupBox3;



    private: System::Windows::Forms::CheckBox^  checkBox3;
    private: System::Windows::Forms::CheckBox^  checkBox2;

    private: System::Windows::Forms::GroupBox^  groupBox1;











    private: System::Windows::Forms::ComboBox^  comboBox1;
    private: System::Windows::Forms::CheckBox^  checkBox4;
    private: System::Windows::Forms::CheckBox^  checkBox5;
    private: System::Windows::Forms::CheckBox^  checkBox6;
    private: System::Windows::Forms::CheckBox^  checkBox7;
    private: System::Windows::Forms::CheckBox^  checkBox8;


    private: System::Windows::Forms::GroupBox^  groupBox4;
    private: System::Windows::Forms::CheckBox^  checkBox1;
    private: System::Windows::Forms::Label^  label3;









    private: System::ComponentModel::IContainer^  components;
    protected: 


    protected: 

    protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->button_initialize = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
            this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->tabControl1->SuspendLayout();
            this->tabPage4->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->tabPage3->SuspendLayout();
            this->SuspendLayout();
            // 
            // button_initialize
            // 
            this->button_initialize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->button_initialize->Location = System::Drawing::Point(200, 8);
            this->button_initialize->Name = L"button_initialize";
            this->button_initialize->Size = System::Drawing::Size(217, 31);
            this->button_initialize->TabIndex = 1;
            this->button_initialize->Text = L"Initialize Code";
            this->button_initialize->UseVisualStyleBackColor = true;
            this->button_initialize->Click += gcnew System::EventHandler(this, &MyForm::button_initialize_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(-5, 1);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(198, 29);
            this->label1->TabIndex = 2;
            this->label1->Text = L"   QuikHop Free";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->label2->Location = System::Drawing::Point(102, 30);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(69, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Version 2.4.1";
            // 
            // tabControl1
            // 
            this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
            this->tabControl1->Controls->Add(this->tabPage4);
            this->tabControl1->Controls->Add(this->tabPage3);
            this->tabControl1->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->tabControl1->HotTrack = true;
            this->tabControl1->Location = System::Drawing::Point(0, 47);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(426, 150);
            this->tabControl1->TabIndex = 5;
            // 
            // tabPage4
            // 
            this->tabPage4->Controls->Add(this->label3);
            this->tabPage4->Controls->Add(this->groupBox4);
            this->tabPage4->Controls->Add(this->groupBox3);
            this->tabPage4->Controls->Add(this->groupBox1);
            this->tabPage4->Location = System::Drawing::Point(4, 4);
            this->tabPage4->Name = L"tabPage4";
            this->tabPage4->Size = System::Drawing::Size(418, 124);
            this->tabPage4->TabIndex = 1;
            this->tabPage4->Text = L"Configuration";
            this->tabPage4->UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(165, 96);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(240, 20);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Thank you for using QuikHop";
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->checkBox1);
            this->groupBox4->Controls->Add(this->checkBox7);
            this->groupBox4->Controls->Add(this->checkBox4);
            this->groupBox4->Controls->Add(this->checkBox6);
            this->groupBox4->Controls->Add(this->checkBox5);
            this->groupBox4->Controls->Add(this->checkBox2);
            this->groupBox4->Location = System::Drawing::Point(162, 3);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(251, 88);
            this->groupBox4->TabIndex = 3;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Toggles";
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Location = System::Drawing::Point(118, 19);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(106, 17);
            this->checkBox1->TabIndex = 9;
            this->checkBox1->Text = L"Toggle Flashlight";
            this->checkBox1->UseVisualStyleBackColor = true;
            this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
            // 
            // checkBox7
            // 
            this->checkBox7->AutoSize = true;
            this->checkBox7->Location = System::Drawing::Point(118, 65);
            this->checkBox7->Name = L"checkBox7";
            this->checkBox7->Size = System::Drawing::Size(82, 17);
            this->checkBox7->TabIndex = 6;
            this->checkBox7->Text = L"Junk Jumps";
            this->checkBox7->UseVisualStyleBackColor = true;
            this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox7_CheckedChanged);
            // 
            // checkBox4
            // 
            this->checkBox4->AutoSize = true;
            this->checkBox4->Location = System::Drawing::Point(7, 42);
            this->checkBox4->Name = L"checkBox4";
            this->checkBox4->Size = System::Drawing::Size(78, 17);
            this->checkBox4->TabIndex = 3;
            this->checkBox4->Text = L"Chat Spam";
            this->checkBox4->UseVisualStyleBackColor = true;
            // 
            // checkBox6
            // 
            this->checkBox6->AutoSize = true;
            this->checkBox6->Location = System::Drawing::Point(118, 42);
            this->checkBox6->Name = L"checkBox6";
            this->checkBox6->Size = System::Drawing::Size(96, 17);
            this->checkBox6->TabIndex = 5;
            this->checkBox6->Text = L"Toggle Crouch";
            this->checkBox6->UseVisualStyleBackColor = true;
            // 
            // checkBox5
            // 
            this->checkBox5->AutoSize = true;
            this->checkBox5->Location = System::Drawing::Point(7, 65);
            this->checkBox5->Name = L"checkBox5";
            this->checkBox5->Size = System::Drawing::Size(85, 17);
            this->checkBox5->TabIndex = 4;
            this->checkBox5->Text = L"Jump Attack";
            this->checkBox5->UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            this->checkBox2->AutoSize = true;
            this->checkBox2->Location = System::Drawing::Point(7, 19);
            this->checkBox2->Name = L"checkBox2";
            this->checkBox2->Size = System::Drawing::Size(105, 17);
            this->checkBox2->TabIndex = 1;
            this->checkBox2->Text = L"Play JumpSound";
            this->checkBox2->UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->comboBox1);
            this->groupBox3->Location = System::Drawing::Point(4, 3);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(152, 49);
            this->groupBox3->TabIndex = 2;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Keybind Settings";
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(16) {L"Space Bar", L"Left Control", L"Right Control", 
                L"Left Shift", L"Right Shift", L"Left Alt", L"Right Alt", L"Left Mouse", L"Right Mouse", L"Middle Mouse", L"Insert", L"Delete", 
                L"Home", L"End", L"Page Up", L"Page Down"});
            this->comboBox1->Location = System::Drawing::Point(6, 19);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(140, 21);
            this->comboBox1->TabIndex = 1;
            this->comboBox1->Text = L"Space Bar";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->checkBox8);
            this->groupBox1->Controls->Add(this->checkBox3);
            this->groupBox1->Location = System::Drawing::Point(4, 55);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(152, 63);
            this->groupBox1->TabIndex = 0;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Developer";
            // 
            // checkBox8
            // 
            this->checkBox8->AutoSize = true;
            this->checkBox8->Location = System::Drawing::Point(6, 19);
            this->checkBox8->Name = L"checkBox8";
            this->checkBox8->Size = System::Drawing::Size(88, 17);
            this->checkBox8->TabIndex = 7;
            this->checkBox8->Text = L"Debug Mode";
            this->checkBox8->UseVisualStyleBackColor = true;
            // 
            // checkBox3
            // 
            this->checkBox3->AutoSize = true;
            this->checkBox3->Location = System::Drawing::Point(6, 41);
            this->checkBox3->Name = L"checkBox3";
            this->checkBox3->Size = System::Drawing::Size(133, 17);
            this->checkBox3->TabIndex = 2;
            this->checkBox3->Text = L"Close after Initialization";
            this->checkBox3->UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this->tabPage3->Controls->Add(this->textBox1);
            this->tabPage3->Location = System::Drawing::Point(4, 4);
            this->tabPage3->Name = L"tabPage3";
            this->tabPage3->Size = System::Drawing::Size(418, 124);
            this->tabPage3->TabIndex = 0;
            this->tabPage3->Text = L"Debug Console";
            this->tabPage3->UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::White;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox1->Location = System::Drawing::Point(0, 0);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->ReadOnly = true;
            this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBox1->Size = System::Drawing::Size(418, 124);
            this->textBox1->TabIndex = 0;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(426, 197);
            this->Controls->Add(this->tabControl1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button_initialize);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"MyForm";
            this->Text = L"QuikHop Free";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->tabControl1->ResumeLayout(false);
            this->tabPage4->ResumeLayout(false);
            this->tabPage4->PerformLayout();
            this->groupBox4->ResumeLayout(false);
            this->groupBox4->PerformLayout();
            this->groupBox3->ResumeLayout(false);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->tabPage3->ResumeLayout(false);
            this->tabPage3->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_initialize_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void add_log(const char *);
    private: System::Void form_resize(int,int,int);
private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
         }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
         }
};
}