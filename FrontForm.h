#pragma once


#include "Login.h"
#include <iostream>
#include <fstream>
#include "MBox.h"



namespace InventorySystem {

	using namespace System;
	using namespace System::Xml;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrontForm
	/// </summary>
	public ref class FrontForm : public System::Windows::Forms::Form
	{


	public:
		blackdog front;
		String^ dbpath, ^ apath, ^ path, ^ close = "false", ^ premclose = "true";

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button3;


	private: System::Windows::Forms::Label^ label5;

	public:

		FrontForm()
		{
			InitializeComponent();
			apath = Application::StartupPath;
			path = apath + "\\InventorySystem.exe.config";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrontForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrontForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label2->Location = System::Drawing::Point(15, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(202, 46);
			this->label2->TabIndex = 3;
			this->label2->Text = L"ARRAY[FOO]\r\n";
			this->label2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseDown);
			this->label2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseMove);
			this->label2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(53, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(375, 62);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Inventory System";
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseUp);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Navy;
			this->label3->Location = System::Drawing::Point(12, 508);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"v R.1.0";
			this->label3->Click += gcnew System::EventHandler(this, &FrontForm::label3_Click);
			this->label3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseDown);
			this->label3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseMove);
			this->label3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseUp);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cyan;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->Location = System::Drawing::Point(65, 277);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(375, 41);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Load Existing Database";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FrontForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Cyan;
			this->button2->Location = System::Drawing::Point(65, 338);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(375, 41);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Create New Database";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FrontForm::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Microsoft Access File|*.accdb";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"Database_User";
			this->saveFileDialog1->Filter = L"Microsoft Access File|*.accdb";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(485, -731);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(424, 1425);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseUp);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Navy;
			this->label5->Location = System::Drawing::Point(173, 512);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(267, 19);
			this->label5->TabIndex = 11;
			this->label5->Text = L"\"Tokio in Feature\" crafted by kevurugames\r\n";
			this->label5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseDown);
			this->label5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseMove);
			this->label5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseUp);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(65, 400);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(375, 41);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Close Application";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FrontForm::button3_Click);
			// 
			// FrontForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(907, 540);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FrontForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Start";
			this->Load += gcnew System::EventHandler(this, &FrontForm::FrontForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FrontForm::FrontForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool dragging;
	private: Point offset;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ target, ^ DBdir, ^ DBname;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			DBdir = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
			DBname = System::IO::Path::GetFileName(openFileDialog1->FileName);
			target = DBdir + "\\" + DBname;
			if (DBdir + "\\InventorySystem.DBCOPY.accdb" == target) {
				MBox^ adform = gcnew MBox("Selected database is a reserved file.", 1);
				adform->ShowDialog();
				delete adform;
				return;
			}

			CreateConfig(openFileDialog1->FileName);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ fn, ^ target, ^ DBdir, ^ DBname;

			DBdir = System::IO::Path::GetDirectoryName(saveFileDialog1->FileName);
			DBname = System::IO::Path::GetFileName(saveFileDialog1->FileName);

			fn = apath + "\\InventorySystem.DBCOPY.accdb";
			target = DBdir + "\\" + DBname;

			if (DBdir + "\\InventorySystem.DBCOPY.accdb" == target) {

				MBox^ adform = gcnew MBox("Filename specified is a reserved word.", 1);
				adform->ShowDialog();
				delete adform;
				return;
			}
			if (IO::File::Exists(target)) {
				IO::File::Delete(target);
			}
			
			if (File::Exists(System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location)+"\\InventorySystem.DBCOPY.accdb")) {
				IO::File::Copy(fn, target);
			}
			else {
				MBox^ adform = gcnew MBox("Application resources are either moved, corrupted, or deleted. Creation of new database file is disabled. Redownload the complete application package.", 1);
				adform->ShowDialog();
				this->Close();
			}

			CreateConfig(saveFileDialog1->FileName);
			this->Close();
		}
	}

	public: void CreateConfig(String^ dest) {


		FileStream^ createFile = gcnew FileStream(path, FileMode::Create);
		StreamWriter^ sw = gcnew StreamWriter(createFile);
		sw->WriteLine("<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n" +
			"");
		sw->Flush();
		sw->Close();
		createFile->Close();
		XmlTextWriter^ writer = gcnew XmlTextWriter(path, nullptr);
		writer->Formatting = Formatting::Indented;
		writer->WriteStartDocument();
		writer->WriteStartElement("configuration");
		writer->WriteStartElement("connectionStrings");
		writer->WriteRaw("\n\<clear/\>\n");
		writer->WriteStartElement("add name=" + "\"ARRAY[FOO]\"\n" + " connectionString =\n" +
			"\t\"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dest +
			"\"\n\tproviderName=\"System.Data.OleDb\"");
		writer->WriteEndElement();
		writer->WriteEndElement();
		writer->Flush();
		writer->Close();

		Application::Restart();
	}



private: System::Void FrontForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->dragging = false;
}





private: System::Void FrontForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) { //Move, soldier, MOVE!
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X,
			currentScreenPos.Y - this->offset.Y);
	}
}
private: System::Void FrontForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}
private: System::Void FrontForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = true;
	this->offset = Point(e->X, e->Y);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
