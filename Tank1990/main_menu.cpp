#include "main_menu.h"
#include "game.h"

#include <Windows.h>

using namespace Tank1990; // пространство имен названия проекта

void main_menu::Decide() {
    if (pictureBox1->Location.Y == 435) {
        game^ GameForm = gcnew game;
        GameForm->Show();
    }
    else if (pictureBox1->Location.Y == 540) {
        MessageBox::Show("2");
    }
    else if (pictureBox1->Location.Y == 645) {
        MessageBox::Show("opt");
    }
    else if (pictureBox1->Location.Y == 750) {
        this->Close();
    }
}

[STAThread] // Без этого не будет открываться fileDialog

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles(); // Иницализировать Visual Styles
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew main_menu); // Запускаем проект

    return 0;
}
