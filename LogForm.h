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
	/// Summary for LogForm
	/// </summary>
	public ref class LogForm : public System::Windows::Forms::Form
	{
	public:
	private: bool dragging;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: Point offset;
	public: void loader(String^ data) {
		int^ netfl = 0, pfl = 0, nfl = 0;
		ntlabel->Text = "Loading";
		rtbProductView->Text = "";
		richTextBox1->Text = "";
		log.reset("search results");
		log.reset("loghp results");
		log.getlog(data);

		if (log.dataContent != false) {

			dataClass^ str = gcnew dataClass;
			str = log.start;
			bool end = false;
			do {
				if (str->last) {
					end = true;
				}
				rtbProductView->AppendText( str->ProductName + "\n\n");
				rtbProductView->AppendText("Brand:\t\t" + str->Brand + "\n");
				rtbProductView->AppendText("Category:\t" + str->Category + "\n");
				rtbProductView->AppendText("Change:\t\t" + str->quantity + "\n");
				rtbProductView->AppendText("Cost:\t\t" + str->price + "\n");
				rtbProductView->AppendText("Date:\t\t" + str->Misc + "\n\n\n");
				if ((int)str->quantity > 0) {
					nfl = (int)nfl + (int)str->price;
				}
				else {
					pfl = (int)pfl + (int)str->price;
				}
				if (str->next != nullptr) {
					str = str->next;
				}
			} while (str->last != true || !end);
			delete str;

			str = log.loghelper;
			end = false;
			do {
				if (str->last) {
					end = true;
				}
				richTextBox1->AppendText("Change: " + str->quantity + "\n");
				richTextBox1->AppendText(str->ProductName + "\n\n");
			
				if (str->next != nullptr) {
					str = str->next;
				}
			} while (str->last != true || !end);
			delete str;
			
		}
		else {
			rtbProductView->Text = "\n\n\n No recorded history.";
		}
		netfl = pfl - nfl;
		ntlabel->Text = "" + netfl;
		plabel->Text = "" + pfl;
		nlabel->Text = "" + nfl;
		if (pfl > nfl) {
			ntlabel->ForeColor = Color::Green;
		}
		else if (pfl < nfl) {
			ntlabel->ForeColor = Color::Red;
		}
		else {
			ntlabel->ForeColor = Color::DodgerBlue;
		}
	}

	private: System::Windows::Forms::Label^ ntlabel;
	private: System::Windows::Forms::Label^ plabel;
	private: System::Windows::Forms::Label^ nlabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;


	public:

		   blackdog log;
		LogForm(void)
		{
			InitializeComponent();
			log.connect();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ rtbProductView;
	private: System::Windows::Forms::Label^ lblHeader;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LogForm::typeid));
			this->rtbProductView = (gcnew System::Windows::Forms::RichTextBox());
			this->lblHeader = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ntlabel = (gcnew System::Windows::Forms::Label());
			this->plabel = (gcnew System::Windows::Forms::Label());
			this->nlabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// rtbProductView
			// 
			this->rtbProductView->BackColor = System::Drawing::Color::White;
			this->rtbProductView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbProductView->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rtbProductView->DetectUrls = false;
			this->rtbProductView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtbProductView->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->rtbProductView->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->rtbProductView->Location = System::Drawing::Point(11, 208);
			this->rtbProductView->Margin = System::Windows::Forms::Padding(4);
			this->rtbProductView->Name = L"rtbProductView";
			this->rtbProductView->ReadOnly = true;
			this->rtbProductView->Size = System::Drawing::Size(735, 686);
			this->rtbProductView->TabIndex = 11;
			this->rtbProductView->Text = L"";
			this->rtbProductView->TextChanged += gcnew System::EventHandler(this, &LogForm::rtbProductView_TextChanged);
			// 
			// lblHeader
			// 
			this->lblHeader->AutoSize = true;
			this->lblHeader->BackColor = System::Drawing::Color::Transparent;
			this->lblHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeader->ForeColor = System::Drawing::Color::Navy;
			this->lblHeader->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->lblHeader->Location = System::Drawing::Point(11, 10);
			this->lblHeader->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblHeader->Name = L"lblHeader";
			this->lblHeader->Size = System::Drawing::Size(168, 50);
			this->lblHeader->TabIndex = 12;
			this->lblHeader->Text = L"Statistics";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->CalendarTitleBackColor = System::Drawing::Color::MidnightBlue;
			this->dateTimePicker1->CalendarTitleForeColor = System::Drawing::Color::Cyan;
			this->dateTimePicker1->CalendarTrailingForeColor = System::Drawing::Color::LightSeaGreen;
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(162, 91);
			this->dateTimePicker1->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(226, 34);
			this->dateTimePicker1->TabIndex = 13;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &LogForm::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(13, 91);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 30);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Select date";
			// 
			// ntlabel
			// 
			this->ntlabel->AutoSize = true;
			this->ntlabel->BackColor = System::Drawing::Color::Transparent;
			this->ntlabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ntlabel->ForeColor = System::Drawing::Color::DodgerBlue;
			this->ntlabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ntlabel->Location = System::Drawing::Point(808, 57);
			this->ntlabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ntlabel->Name = L"ntlabel";
			this->ntlabel->Size = System::Drawing::Size(108, 35);
			this->ntlabel->TabIndex = 16;
			this->ntlabel->Text = L"Loading";
			// 
			// plabel
			// 
			this->plabel->AutoSize = true;
			this->plabel->BackColor = System::Drawing::Color::Transparent;
			this->plabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plabel->ForeColor = System::Drawing::Color::Green;
			this->plabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->plabel->Location = System::Drawing::Point(509, 57);
			this->plabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->plabel->Name = L"plabel";
			this->plabel->Size = System::Drawing::Size(80, 35);
			this->plabel->TabIndex = 17;
			this->plabel->Text = L"00000";
			// 
			// nlabel
			// 
			this->nlabel->AutoSize = true;
			this->nlabel->BackColor = System::Drawing::Color::Transparent;
			this->nlabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nlabel->ForeColor = System::Drawing::Color::Red;
			this->nlabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->nlabel->Location = System::Drawing::Point(509, 95);
			this->nlabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nlabel->Name = L"nlabel";
			this->nlabel->Size = System::Drawing::Size(80, 35);
			this->nlabel->TabIndex = 18;
			this->nlabel->Text = L"00000";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Green;
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(476, 49);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 46);
			this->label3->TabIndex = 19;
			this->label3->Text = L"+";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label4->Location = System::Drawing::Point(476, 78);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 60);
			this->label4->TabIndex = 20;
			this->label4->Text = L"-";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel3->Location = System::Drawing::Point(11, 139);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1309, 2);
			this->panel3->TabIndex = 25;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label5->Location = System::Drawing::Point(13, 152);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(85, 30);
			this->label5->TabIndex = 26;
			this->label5->Text = L"History";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(1295, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 27;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &LogForm::pictureBox1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->nlabel);
			this->panel1->Controls->Add(this->plabel);
			this->panel1->Controls->Add(this->ntlabel);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(-1, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1337, 142);
			this->panel1->TabIndex = 28;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::FrontForm_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::FrontForm_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::FrontForm_MouseUp);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label6->Location = System::Drawing::Point(750, 61);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 30);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Net";
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox1->DetectUrls = false;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->richTextBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->richTextBox1->Location = System::Drawing::Point(754, 208);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(565, 686);
			this->richTextBox1->TabIndex = 29;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(748, 152);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 30);
			this->label2->TabIndex = 30;
			this->label2->Text = L"Net Stock Quantity Change";
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(11, 142);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1308, 59);
			this->panel2->TabIndex = 31;
			// 
			// LogForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1332, 908);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->lblHeader);
			this->Controls->Add(this->rtbProductView);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LogForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Database Log";
			this->Load += gcnew System::EventHandler(this, &LogForm::LogForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rtbProductView_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void LogForm_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ filter, ^ now;
		String^ dt = DateTime::Now.ToString();
		DateTime datevalue = (Convert::ToDateTime(dt->ToString()));

		now = datevalue.Month.ToString() + "/" + datevalue.Day.ToString() + "/" + datevalue.Year.ToString();
		loader(now);

	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		loader(dateTimePicker1->Text);
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



	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
