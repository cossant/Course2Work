#pragma once

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

			oleDbConnection1->Open();
			myDs = gcnew DataSet();
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
			this->dataGridView1->Location = System::Drawing::Point(39, 34);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(348, 214);
			this->dataGridView1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(39, 255);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(348, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(151, 281);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainform::button1_Click);
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 326);
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
		System::Data::DataSet^ myDs;
		// ���������� ����� �����.
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		enactCommand(textBox1->Text);
		if (textBox1->Text->Contains("SELECT"))
			showTable("�����");
	}
	private: 
		System::Void enactCommand(System::String^ command);
		System::Void showTable(System::String^ table);
};
}
