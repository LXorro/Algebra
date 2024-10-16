#pragma once

namespace CppCLRWinFormsProject {

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_3;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ button1;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_3 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Manrope", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(578, 41);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Resolucion de sistemas de ecuaciones";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// btn_3
			// 
			this->btn_3->Location = System::Drawing::Point(115, 331);
			this->btn_3->Name = L"btn_3";
			this->btn_3->Size = System::Drawing::Size(111, 52);
			this->btn_3->TabIndex = 1;
			this->btn_3->Text = L"3x3";
			this->btn_3->UseVisualStyleBackColor = true;
			this->btn_3->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// btn4
			// 
			this->btn4->Location = System::Drawing::Point(423, 331);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(111, 52);
			this->btn4->TabIndex = 2;
			this->btn4->Text = L"4x4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form1::btn4_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(264, 422);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 37);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 492);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn_3);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
