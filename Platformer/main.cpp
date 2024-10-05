#include "main.h"
#include "Character.h"



int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };

    const int screenWidth = 1900;
    const int screenHeight = 1000;

    const int charWidth = 30;
    const int charHeight = 50;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "Platformer");
    SetTargetFPS(60);

    Character perso(screenWidth / 2 - charWidth / 2, screenHeight - charHeight);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Color{ 255,255,255,255 });

        perso.Update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}