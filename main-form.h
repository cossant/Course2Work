#pragma once
#include "add-guest-form.h"
#include "data-ask-form.h"


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

			// Basic output.
			oleDbConnection1->Open();
			myDs = gcnew DataSet();
			oleDbSelectCommand1->CommandText = L"SELECT * FROM �����";
			oleDbSelectCommand1->Connection = oleDbConnection1;
			oleDbDataAdapter1->Fill(myDs);
			dataGridView1->DataSource = myDs;
			dataGridView1->DataMember = "�����";
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
	protected:







	protected:

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// oleDbSelectCommand1
			// 
			this->oleDbSelectCommand1->CommandText = L"SELECT �����.*, �������.*, �����.* FROM((����� INNER JOIN ������� ON �����.[���_�"
				L"�������] = �������.[���_��������]) INNER JOIN ����� ON �������.[���_������] = ��"
				L"���.[���_������])";
			this->oleDbSelectCommand1->Connection = this->oleDbConnection1;
			// 
			// oleDbConnection1
			// 
			this->oleDbConnection1->ConnectionString = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=\"D:\\����\\������\\������������ ������"
				L"��\\��������\\HotelBase.accdb\"";
			// 
			// oleDbDataAdapter1
			// 
			this->oleDbDataAdapter1->SelectCommand = this->oleDbSelectCommand1;
			cli::array< System::Data::Common::DataColumnMapping^ >^ __mcTemp__1 = gcnew cli::array< System::Data::Common::DataColumnMapping^  >(11) {
				(gcnew System::Data::Common::DataColumnMapping(L"�����.���_��������",
					L"���_��������")), (gcnew System::Data::Common::DataColumnMapping(L"�������", L"�������")), (gcnew System::Data::Common::DataColumnMapping(L"���",
						L"���")), (gcnew System::Data::Common::DataColumnMapping(L"��������", L"��������")), (gcnew System::Data::Common::DataColumnMapping(L"���_��������",
							L"���_��������")), (gcnew System::Data::Common::DataColumnMapping(L"�������.���_������", L"�������.���_������")), (gcnew System::Data::Common::DataColumnMapping(L"�������.���_��������",
								L"�������.���_��������")), (gcnew System::Data::Common::DataColumnMapping(L"����_����������", L"����_����������")), (gcnew System::Data::Common::DataColumnMapping(L"������������",
									L"������������")), (gcnew System::Data::Common::DataColumnMapping(L"�����.���_������", L"�����.���_������")), (gcnew System::Data::Common::DataColumnMapping(L"���_����",
										L"���_����"))
			};
			this->oleDbDataAdapter1->TableMappings->AddRange(gcnew cli::array< System::Data::Common::DataTableMapping^  >(1) {
				(gcnew System::Data::Common::DataTableMapping(L"Table",
					L"�����", __mcTemp__1))
			});
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(39, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(497, 215);
			this->dataGridView1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(39, 285);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(497, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(184, 311);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 19);
			this->button1->TabIndex = 2;
			this->button1->Text = L"������ ���������� �������� SQL";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainform::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(503, 233);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 47);
			this->button2->TabIndex = 3;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &mainform::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(379, 233);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 46);
			this->button3->TabIndex = 4;
			this->button3->Text = L"��������������� �����";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &mainform::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(211, 233);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(160, 22);
			this->button4->TabIndex = 5;
			this->button4->Text = L"�����������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &mainform::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(211, 256);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(160, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"��������� ������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &mainform::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(43, 231);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(162, 24);
			this->button6->TabIndex = 7;
			this->button6->Text = L"����������� �����...";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &mainform::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(43, 256);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(162, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"�����������... ";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 342);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"mainform";
			this->Text = L"Information Hotel System";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// ���������� ����� �����.
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
};
}
