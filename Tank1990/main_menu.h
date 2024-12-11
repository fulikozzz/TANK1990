#pragma once

namespace Tank1990 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ main_menu
	/// </summary>
	public ref class main_menu : public System::Windows::Forms::Form
	{
	public:
		main_menu(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~main_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ Decide_pictureBox;
	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_menu::typeid));
			this->Decide_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Decide_pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// Decide_pictureBox
			// 
			this->Decide_pictureBox->BackColor = System::Drawing::Color::Transparent;
			this->Decide_pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Decide_pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Decide_pictureBox.Image")));
			this->Decide_pictureBox->Location = System::Drawing::Point(605, 435);
			this->Decide_pictureBox->Name = L"Decide_pictureBox";
			this->Decide_pictureBox->Size = System::Drawing::Size(60, 60);
			this->Decide_pictureBox->TabIndex = 0;
			this->Decide_pictureBox->TabStop = false;
			// 
			// main_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->Decide_pictureBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"main_menu";
			this->Text = L"TANK1990";
			this->Load += gcnew System::EventHandler(this, &main_menu::main_menu_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &main_menu::main_menu_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Decide_pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void main_menu_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: void Decide();
	private: System::Void main_menu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
