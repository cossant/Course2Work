#pragma once
#include "add-guest-form.h"
#include "data-ask-form.h"
#include "ask-days-form.h"
#include "add-contract-form.h"


namespace HotelInfoSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainform : public System::Windows::Forms::Form
	{
	public:
		mainform(System::String^ workfilePath)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Data input setting.
			this->oleDbConnection1->ConnectionString = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=\"" + workfilePath + "\"";

			// Basic output.
			oleDbConnection1->Open();
			myDs = gcnew DataSet();
			oleDbSelectCommand1->CommandText = L"SELECT * FROM Гость";
			oleDbSelectCommand1->Connection = oleDbConnection1;
			oleDbDataAdapter1->Fill(myDs);
			dataGridView1->DataSource = myDs;
			dataGridView1->DataMember = "Гость";
			oleDbConnection1->Close();

			// Data description.
			descLabel->Text = L"Зарегистрированные гости";

			// Button activated.
			button8->Enabled = true;
		}
		
		mainform()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->oleDbConnection1->ConnectionString = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=\"" 
				+ "C:\\Users\\user\\source\\repos\\HotelInfoSystem\\HotelBase.accdb" + "\"";

			// Basic output.
			oleDbConnection1->Open();
			myDs = gcnew DataSet();
			oleDbSelectCommand1->CommandText = L"SELECT * FROM Гость";
			oleDbSelectCommand1->Connection = oleDbConnection1;
			oleDbDataAdapter1->Fill(myDs);
			dataGridView1->DataSource = myDs;
			dataGridView1->DataMember = "Гость";
			oleDbConnection1->Close();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Data::OleDb::OleDbCommand^ oleDbSelectCommand1;
	protected:
	private: System::Data::OleDb::OleDbConnection^ oleDbConnection1;
	private: System::Data::OleDb::OleDbDataAdapter^ oleDbDataAdapter1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ descLabel;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button9;
	
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
		void InitializeComponent()
		{
			this->oleDbSelectCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbConnection1 = (gcnew System::Data::OleDb::OleDbConnection());
			this->oleDbDataAdapter1 = (gcnew System::Data::OleDb::OleDbDataAdapter());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->descLabel = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// oleDbSelectCommand1
			// 
			this->oleDbSelectCommand1->CommandText = L"SELECT Гость.*, Договор.*, Номер.* FROM((Гость INNER JOIN Договор ON Гость.[Код_п"
				L"аспорта] = Договор.[Код_паспорта]) INNER JOIN Номер ON Договор.[Код_номера] = Но"
				L"мер.[Код_номера])";
			this->oleDbSelectCommand1->Connection = this->oleDbConnection1;
			// 
			// oleDbDataAdapter1
			// 
			this->oleDbDataAdapter1->SelectCommand = this->oleDbSelectCommand1;
			cli::array< System::Data::Common::DataColumnMapping^ >^ __mcTemp__1 = gcnew cli::array< System::Data::Common::DataColumnMapping^  >(11) {
				(gcnew System::Data::Common::DataColumnMapping(L"Гость.Код_паспорта",
					L"Код_паспорта")), (gcnew System::Data::Common::DataColumnMapping(L"Фамилия", L"Фамилия")), (gcnew System::Data::Common::DataColumnMapping(L"Имя",
						L"Имя")), (gcnew System::Data::Common::DataColumnMapping(L"Отчество", L"Отчество")), (gcnew System::Data::Common::DataColumnMapping(L"Код_договора",
							L"Код_договора")), (gcnew System::Data::Common::DataColumnMapping(L"Договор.Код_номера", L"Договор.Код_номера")), (gcnew System::Data::Common::DataColumnMapping(L"Договор.Код_паспорта",
								L"Договор.Код_паспорта")), (gcnew System::Data::Common::DataColumnMapping(L"Дата_подписания", L"Дата_подписания")), (gcnew System::Data::Common::DataColumnMapping(L"Длительность",
									L"Длительность")), (gcnew System::Data::Common::DataColumnMapping(L"Номер.Код_номера", L"Номер.Код_номера")), (gcnew System::Data::Common::DataColumnMapping(L"Код_типа",
										L"Код_типа"))
			};
			this->oleDbDataAdapter1->TableMappings->AddRange(gcnew cli::array< System::Data::Common::DataTableMapping^  >(1) {
				(gcnew System::Data::Common::DataTableMapping(L"Table",
					L"Гость", __mcTemp__1))
			});
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(60, 93);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(488, 214);
			this->dataGridView1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(53, 376);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(497, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(200, 402);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 19);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Прямое исполнение комманды SQL";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainform::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(127, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 22);
			this->button2->TabIndex = 3;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &mainform::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(3, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 46);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Зафиксированные гости";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &mainform::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(335, 322);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(215, 22);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Проживающие";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &mainform::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(335, 346);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(215, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Свободные номера";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &mainform::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(53, 321);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(219, 24);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Просмотреть выезд...";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &mainform::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(53, 346);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(219, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Долгожители... ";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &mainform::button7_Click);
			// 
			// descLabel
			// 
			this->descLabel->AutoSize = true;
			this->descLabel->Location = System::Drawing::Point(78, 83);
			this->descLabel->Name = L"descLabel";
			this->descLabel->Size = System::Drawing::Size(0, 13);
			this->descLabel->TabIndex = 9;
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Location = System::Drawing::Point(127, 26);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(33, 23);
			this->button8->TabIndex = 10;
			this->button8->Text = L"-";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &mainform::button8_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(77, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(165, 53);
			this->panel1->TabIndex = 11;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(355, 13);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(165, 53);
			this->button9->TabIndex = 12;
			this->button9->Text = L"Оформить аренду номера";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &mainform::button9_Click);
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 440);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->descLabel);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"mainform";
			this->Text = L"Information Hotel System";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Рукописные члены формы.
	public:
		System::Void showTable(System::String^ table);
		System::Void enactCommand(System::String^ command);
	protected:
		System::Data::DataSet^ myDs;
	private: 
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
