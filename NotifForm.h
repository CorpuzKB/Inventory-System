#pragma once
#include "blackdog.h"
#include "MBox.h"


namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NotifForm
	/// </summary>
	public ref class NotifForm : public System::Windows::Forms::Form
	{
	public:
		blackdog watchd;

	public: void sync() {
		rtbProductView->Text = "";
		numQty->Text = watchd.getSettings("StockWarningLevel");
		label3->Text = watchd.getStockLow();
		watchd.reset("search results");
		watchd.getStockStatus();
		dataClass^ str = gcnew dataClass;
		str = watchd.start;

		bool end = false;
		if (str->ProductName != nullptr) {
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
		delete str;
	}

		NotifForm(void)
		{
			InitializeComponent();
			watchd.connect();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NotifForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ lblProduct;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::NumericUpDown^ numQty;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RichTextBox^ rtbProductView;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NotifForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblProduct = (gcnew System::Windows::Forms::Label());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->numQty = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->rtbProductView = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQty))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label2->Location = System::Drawing::Point(11, 10);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(348, 46);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Inventory Watchdog";
			// 
			// lblProduct
			// 
			this->lblProduct->AutoSize = true;
			this->lblProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProduct->ForeColor = System::Drawing::Color::Navy;
			this->lblProduct->Location = System::Drawing::Point(14, 121);
			this->lblProduct->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblProduct->Name = L"lblProduct";
			this->lblProduct->Size = System::Drawing::Size(293, 28);
			this->lblProduct->TabIndex = 23;
			this->lblProduct->Text = L"Detect stock quantity less than";
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnUpdate->FlatAppearance->BorderSize = 0;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdate->ForeColor = System::Drawing::Color::Cyan;
			this->btnUpdate->Location = System::Drawing::Point(504, 116);
			this->btnUpdate->Margin = System::Windows::Forms::Padding(4);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(144, 38);
			this->btnUpdate->TabIndex = 24;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &NotifForm::btnUpdate_Click);
			// 
			// numQty
			// 
			this->numQty->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->numQty->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numQty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numQty->ForeColor = System::Drawing::Color::White;
			this->numQty->InterceptArrowKeys = false;
			this->numQty->Location = System::Drawing::Point(347, 119);
			this->numQty->Margin = System::Windows::Forms::Padding(4);
			this->numQty->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numQty->Name = L"numQty";
			this->numQty->Size = System::Drawing::Size(70, 34);
			this->numQty->TabIndex = 22;
			this->numQty->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numQty->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->rtbProductView);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(0, 180);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1235, 722);
			this->panel1->TabIndex = 25;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(151, 5);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 28);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Loading";
			// 
			// rtbProductView
			// 
			this->rtbProductView->BackColor = System::Drawing::Color::White;
			this->rtbProductView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbProductView->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rtbProductView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtbProductView->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->rtbProductView->Location = System::Drawing::Point(12, 43);
			this->rtbProductView->Name = L"rtbProductView";
			this->rtbProductView->Size = System::Drawing::Size(1220, 610);
			this->rtbProductView->TabIndex = 0;
			this->rtbProductView->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Navy;
			this->label1->Location = System::Drawing::Point(14, 5);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 28);
			this->label1->TabIndex = 27;
			this->label1->Text = L"Items found:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel3->Location = System::Drawing::Point(18, 180);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1214, 2);
			this->panel3->TabIndex = 26;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Navy;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pictureBox2->Location = System::Drawing::Point(1210, 10);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(25, 25);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 27;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &NotifForm::pictureBox2_Click);
			// 
			// NotifForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1247, 845);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->lblProduct);
			this->Controls->Add(this->numQty);
			this->Controls->Add(this->label2);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Transparent;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NotifForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stock Data";
			this->Load += gcnew System::EventHandler(this, &NotifForm::NotifForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQty))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void NotifForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		sync();
	}


	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		watchd.updateSettings("StockWarningLevel", numQty->Text);
		sync();
	}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
