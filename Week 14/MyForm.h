#pragma once
#include "Controller.h"
#include "FileManager.h"

namespace Re {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Controller* game;
		FileManager* config;
		Bitmap^ bmpPlayer;
		Bitmap^ bmpGhost;
		Bitmap^ bmpBonus;
		Bitmap^ bmpPacdot;

	private: System::Windows::Forms::Timer^ timer1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			config = new FileManager();
			game = new Controller(config->getLives(), config->getGhostQty(), config->getPacDotsQty());
			bmpPlayer = gcnew Bitmap("sprites.png");
			bmpGhost = gcnew Bitmap("sprites.png");
			bmpBonus = gcnew Bitmap("bonus.png");
			bmpPacdot = gcnew Bitmap("pacdot.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete game, bmpPlayer, bmpGhost, bmpBonus, bmpPacdot;
		}
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up: game->movePlayer(direccion::up); break;
		case Keys::Down: game->movePlayer(direccion::down); break;
		case Keys::Left: game->movePlayer(direccion::left); break;
		case Keys::Right: game->movePlayer(direccion::right);
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		bf->Graphics->Clear(Color::White);

		game->gameManagement(bf->Graphics, bmpPlayer, bmpGhost, bmpBonus, bmpPacdot);

		bf->Render(g);
		delete g, espacio, bf;

		if (game->isGameOver()) {
			timer1->Enabled = false;
			MessageBox::Show("PUEDES VER TU PUNTUACION EN EL ARCHIVO INPUT.TXT", "GAME OVER", MessageBoxButtons::OK, MessageBoxIcon::Information);
			config->saveScore(game->getScore());
			this->Close();
		}
	}
	};
}
