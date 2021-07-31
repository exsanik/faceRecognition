#pragma once
#include"Libs.h"

namespace FaceRecognition {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void MarshalString(String ^ s, std::string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	/// <summary>
	/// Сводка для Save
	/// </summary>
	public ref class Save : public System::Windows::Forms::Form
	{
	public:
		
		Save(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Save()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		cv::Mat &photo = cv::Mat();
		Person &smone = Person();
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Save::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(53, 21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(175, 211);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(255, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Имя";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(260, 71);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(176, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(260, 149);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(176, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(255, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Фамилия";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(53, 268);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 52);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Закрыть";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Save::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(291, 268);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 52);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Save::button2_Click);
			// 
			// Save
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(503, 378);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Save";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Save";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->pictureBox1->Image = nullptr;
			this->Close();
		}
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (textBox1->Text == "")
			{
				MessageBox::Show("Нужно заполнить поле имя!");
				return;
			}
			if (textBox2->Text == "")
			{
				MessageBox::Show("Нужно заполнить поле фамилия!");
				return;
			}

			std::string n1; 
			MarshalString((textBox1->Text), n1);
			std::string n2;
			MarshalString((textBox2->Text), n2);

			smone.setName(n1);
			smone.setfamName(n2);
			std::string path = "img/"+std::to_string(smone.getCurrId())+"["+std::to_string(smone.getPicAmount())+"].jpg";
			cv::imwrite(path, photo);
			smone.addImage(path);
			smone.saveToFile();
			
			this->Close();
		}
		public: System::Void setPictureBox(cv::Mat pic)
		{
			photo = pic;
			pictureBox1->Image = gcnew System::Drawing::Bitmap(pic.cols, pic.rows, pic.step1(), System::Drawing::Imaging::PixelFormat::Format24bppRgb, IntPtr(pic.data));
		}
		
};
}
