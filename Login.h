#pragma once
#include "blackdog.h"
#include "admin.h"
#include "NewProduct.h"
#include "MBox.h"
#include "FirstTimeForm.h"
#include <iostream>
#include <fstream>



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
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
		blackdog two;
		String^ dbpath, ^ apath, ^path;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: bool dragging;
	private: Point offset;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	public:
		Login(String^ arg)
		{
			InitializeComponent();
			apath = arg;
			path = apath + "\\InventorySystem.exe.config";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ employeeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ customerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ employeeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ customerToolStripMenuItem1;
	private: System::Windows::Forms::Label^ lblHeader;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnProdSearch;
	private: System::Windows::Forms::TextBox^ txtBoxProdSearch;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RichTextBox^ rtbProductView;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ rdbtnDef;
	private: System::Windows::Forms::RadioButton^ rdbtnPAsc;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::RadioButton^ rdbtnPDesc;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->employeeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->employeeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customerToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblHeader = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnProdSearch = (gcnew System::Windows::Forms::Button());
			this->txtBoxProdSearch = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->rtbProductView = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rdbtnDef = (gcnew System::Windows::Forms::RadioButton());
			this->rdbtnPAsc = (gcnew System::Windows::Forms::RadioButton());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->rdbtnPDesc = (gcnew System::Windows::Forms::RadioButton());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// employeeToolStripMenuItem
			// 
			this->employeeToolStripMenuItem->Name = L"employeeToolStripMenuItem";
			resources->ApplyResources(this->employeeToolStripMenuItem, L"employeeToolStripMenuItem");
			// 
			// customerToolStripMenuItem
			// 
			this->customerToolStripMenuItem->Name = L"customerToolStripMenuItem";
			resources->ApplyResources(this->customerToolStripMenuItem, L"customerToolStripMenuItem");
			// 
			// employeeToolStripMenuItem1
			// 
			this->employeeToolStripMenuItem1->Name = L"employeeToolStripMenuItem1";
			resources->ApplyResources(this->employeeToolStripMenuItem1, L"employeeToolStripMenuItem1");
			// 
			// customerToolStripMenuItem1
			// 
			this->customerToolStripMenuItem1->Name = L"customerToolStripMenuItem1";
			resources->ApplyResources(this->customerToolStripMenuItem1, L"customerToolStripMenuItem1");
			// 
			// lblHeader
			// 
			resources->ApplyResources(this->lblHeader, L"lblHeader");
			this->lblHeader->BackColor = System::Drawing::Color::Transparent;
			this->lblHeader->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblHeader->ForeColor = System::Drawing::Color::Cyan;
			this->lblHeader->Name = L"lblHeader";
			this->lblHeader->Click += gcnew System::EventHandler(this, &Login::label1_Click);
			this->lblHeader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseDown);
			this->lblHeader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseMove);
			this->lblHeader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseUp);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::Blue;
			this->btnLogin->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btnLogin, L"btnLogin");
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &Login::btnLogin_Click);
			// 
			// btnProdSearch
			// 
			this->btnProdSearch->BackColor = System::Drawing::Color::Blue;
			this->btnProdSearch->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnProdSearch->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->btnProdSearch, L"btnProdSearch");
			this->btnProdSearch->ForeColor = System::Drawing::Color::White;
			this->btnProdSearch->Name = L"btnProdSearch";
			this->btnProdSearch->UseVisualStyleBackColor = false;
			this->btnProdSearch->Click += gcnew System::EventHandler(this, &Login::btnProdSearch_Click);
			// 
			// txtBoxProdSearch
			// 
			this->txtBoxProdSearch->BackColor = System::Drawing::Color::Navy;
			this->txtBoxProdSearch->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->txtBoxProdSearch, L"txtBoxProdSearch");
			this->txtBoxProdSearch->ForeColor = System::Drawing::Color::White;
			this->txtBoxProdSearch->Name = L"txtBoxProdSearch";
			this->txtBoxProdSearch->Click += gcnew System::EventHandler(this, &Login::txtBoxProdSearch_Click);
			this->txtBoxProdSearch->TextChanged += gcnew System::EventHandler(this, &Login::txtBoxProdSearch_TextChanged);
			this->txtBoxProdSearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Login::txtBoxProdSearch_KeyPress);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Cyan;
			resources->ApplyResources(this->panel2, L"panel2");
			this->panel2->Name = L"panel2";
			// 
			// rtbProductView
			// 
			this->rtbProductView->BackColor = System::Drawing::Color::MidnightBlue;
			this->rtbProductView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbProductView->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rtbProductView->DetectUrls = false;
			resources->ApplyResources(this->rtbProductView, L"rtbProductView");
			this->rtbProductView->ForeColor = System::Drawing::Color::White;
			this->rtbProductView->Name = L"rtbProductView";
			this->rtbProductView->ReadOnly = true;
			this->rtbProductView->TextChanged += gcnew System::EventHandler(this, &Login::rtbProductView_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel1->Controls->Add(this->rtbProductView);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Login::panel1_Paint);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &Login::label1_Click_2);
			// 
			// rdbtnDef
			// 
			resources->ApplyResources(this->rdbtnDef, L"rdbtnDef");
			this->rdbtnDef->Checked = true;
			this->rdbtnDef->FlatAppearance->BorderSize = 0;
			this->rdbtnDef->Name = L"rdbtnDef";
			this->rdbtnDef->TabStop = true;
			this->rdbtnDef->UseVisualStyleBackColor = true;
			this->rdbtnDef->CheckedChanged += gcnew System::EventHandler(this, &Login::rdbtnDef_CheckedChanged);
			// 
			// rdbtnPAsc
			// 
			resources->ApplyResources(this->rdbtnPAsc, L"rdbtnPAsc");
			this->rdbtnPAsc->FlatAppearance->BorderSize = 0;
			this->rdbtnPAsc->Name = L"rdbtnPAsc";
			this->rdbtnPAsc->UseVisualStyleBackColor = true;
			this->rdbtnPAsc->CheckedChanged += gcnew System::EventHandler(this, &Login::rdbtnPAsc_CheckedChanged);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->rdbtnPDesc);
			this->panel3->Controls->Add(this->rdbtnPAsc);
			this->panel3->Controls->Add(this->rdbtnDef);
			resources->ApplyResources(this->panel3, L"panel3");
			this->panel3->Name = L"panel3";
			// 
			// rdbtnPDesc
			// 
			resources->ApplyResources(this->rdbtnPDesc, L"rdbtnPDesc");
			this->rdbtnPDesc->FlatAppearance->BorderSize = 0;
			this->rdbtnPDesc->Name = L"rdbtnPDesc";
			this->rdbtnPDesc->UseVisualStyleBackColor = true;
			this->rdbtnPDesc->CheckedChanged += gcnew System::EventHandler(this, &Login::rdbtnPDesc_CheckedChanged);
			// 
			// openFileDialog1
			// 
			resources->ApplyResources(this->openFileDialog1, L"openFileDialog1");
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Name = L"label2";
			this->label2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseDown);
			this->label2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseMove);
			this->label2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseUp);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseUp);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Navy;
			resources->ApplyResources(this->pictureBox2, L"pictureBox2");
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Login::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Navy;
			resources->ApplyResources(this->pictureBox3, L"pictureBox3");
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Login::pictureBox3_Click);
			// 
			// Login
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::Navy;
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->btnProdSearch);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->lblHeader);
			this->Controls->Add(this->txtBoxProdSearch);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::Transparent;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::FrontForm_MouseUp);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {

		Login::Hide();
		if (File::Exists(path)) {
			try{
				two.connect();
				two.search("", "ProductName ASC");
			}
			catch (Exception^ ex) {
				IO::File::Delete(path);
				String^ msg = "The selected database file has invalid structure. The configuration file has been reset. Try again.";
				MBox^ adform = gcnew MBox(msg, 1);
				adform->ShowDialog();
				if (adform->ReturnData() == "true") {
					Application::Restart();
				}
			}
			Login::Show();

			if (two.adminLogin("ARRAY[FOO]")) {
				FirstTimeForm^ adform = gcnew FirstTimeForm();
				adform->ShowDialog();
			}
		}
		else {
			String^ msg = "Application configuration file is corrupted. Restart?";
			MBox^ adform = gcnew MBox(msg, 1);
			adform->ShowDialog();
			delete adform;
			Application::Restart();

		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		admin^ ad = gcnew admin(apath);
		ad->Show();
	}

	private: System::Void txtboxLogin_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtBoxProdSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnProdSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		srch();
	}
	private: System::Void rtbProductView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rdbtnPDesc_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
}

private: System::Void txtBoxProdSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxProdSearch->Text == "Type an item") {
		txtBoxProdSearch->Text = "";
	}	
}

private: System::Void txtBoxProdSearch_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == 13) {
		srch();
	}
}

private: System::Void srch() {
	String^ filter;
	rtbProductView->Text = "";
	if (rdbtnDef->Checked == 1) {
		filter = "ProductName ASC";
	}
	else if (rdbtnPAsc->Checked == 1) {
		filter = "Price ASC";
	}
	else {
		filter = "Price DESC";
	}
	two.reset("search results");
	String^ keySearch = txtBoxProdSearch->Text;
	two.search(keySearch->Trim(), filter);
	dataClass^ str = gcnew dataClass;
	str = two.start;

	bool end = false;
	if (str->ProductName == nullptr) {
		rtbProductView->AppendText("\nNo items found\n");
	}
	else {
		do {
			if (str->last) {
				end = true;
			}
			rtbProductView->AppendText("Name:\t\t" + str->ProductName + "\n");
			rtbProductView->AppendText("Brand:\t\t" + str->Brand + "\n");
			rtbProductView->AppendText("Category:\t" + str->Category + "\n");
			rtbProductView->AppendText("Stock:\t\t" + str->quantity + "\n");
			rtbProductView->AppendText("Price:\t\t" + str->price + "\n\n\n");
			if (str->next != nullptr) {
				str = str->next;
			}
		} while (str->last != true || !end);
	}
}

private: System::Void rdbtnDef_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void rdbtnPAsc_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

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

private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;
}
};
}
