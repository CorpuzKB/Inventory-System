#pragma once
#include "blackdog.h"
#include "MyForm.h"
#include "MBox.h"




namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for admin
	/// </summary>
	public ref class admin : public System::Windows::Forms::Form
	{
		blackdog entrance;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   String^ path;
	public:

		

		admin(String^ data)
		{
			path = data;
			InitializeComponent();
			entrance.connect();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtboxLogin;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(admin::typeid));
			this->txtboxLogin = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtboxLogin
			// 
			this->txtboxLogin->BackColor = System::Drawing::Color::Black;
			this->txtboxLogin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtboxLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxLogin->ForeColor = System::Drawing::Color::White;
			this->txtboxLogin->Location = System::Drawing::Point(36, 126);
			this->txtboxLogin->Name = L"txtboxLogin";
			this->txtboxLogin->PasswordChar = '*';
			this->txtboxLogin->Size = System::Drawing::Size(439, 31);
			this->txtboxLogin->TabIndex = 0;
			this->txtboxLogin->TextChanged += gcnew System::EventHandler(this, &admin::textBox1_TextChanged);
			this->txtboxLogin->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &admin::txtboxLogin_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(31, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Password";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Blue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(349, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 38);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Log in";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &admin::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(28, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(236, 45);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Administrator\r\n";
			this->label2->Click += gcnew System::EventHandler(this, &admin::label2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(36, 155);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(439, 2);
			this->panel1->TabIndex = 4;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(473, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &admin::pictureBox1_Click);
			// 
			// admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(510, 243);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtboxLogin);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"admin";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Admin prompt";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &admin::admin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		validate();
	}
	private: System::Void admin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtboxLogin_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == 13) {
		validate();
	}
}

public: System::Void validate () {

	if (entrance.adminLogin(txtboxLogin->Text))
	{
		MyForm^ mainform = gcnew MyForm(path);
		mainform->Show();
		this->Close();

	}
	else
	{
		String^ msg = "Incorrect password. Contact your administrator for credentials.";
		MBox^ adform = gcnew MBox(msg, 1);
		adform->ShowDialog();
		delete adform;
		txtboxLogin->Text = "";
	}

}


private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
