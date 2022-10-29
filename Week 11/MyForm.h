#pragma once
#include "Controller.h"

namespace Taller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->game = new Controller();
			this->bmpEscenario = gcnew Bitmap(".\\sprites\\grass.png");
			this->bmpPlayer = gcnew Bitmap(".\\sprites\\playerC.png");
			this->bmpCoin = gcnew Bitmap(".\\sprites\\coin.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete this->game, this->bmpEscenario, this->bmpPlayer, this->bmpCoin, this->music;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Controller* game;
		Bitmap^ bmpEscenario;
		Bitmap^ bmpPlayer;
		Bitmap^ bmpCoin;
		SoundPlayer^ music = gcnew SoundPlayer(".\\sounds\\level_one.wav");
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"PUNTOS: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();
			//
			// Music
			//
			this->music->PlayLooping();
		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		bf->Graphics->Clear(Color::White);
		
		this->game->gameManagement(bf->Graphics, bmpEscenario, bmpPlayer, bmpCoin);
		this->label1->Text = "PUNTOS: " + Convert::ToString(this->game->getPoints());

		bf->Render(g);
		delete g, espacio, bf;
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W: this->game->keyManagement(direccion::up); break;
		case Keys::S: this->game->keyManagement(direccion::down); break;
		case Keys::A: this->game->keyManagement(direccion::left); break;
		case Keys::D: this->game->keyManagement(direccion::right); break;
		case Keys::Space: this->music->Stop(); break;
		case Keys::P: this->music->PlayLooping(); break;
		case Keys::Escape: this->Close();
		}
	}
	};
}
