#include "main.h"


int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };

    const int screenWidth = 1900;
    const int screenHeight = 1000;

    const int charWidth = 30;
    const int charHeight = 50;


    InitWindow(screenWidth, screenHeight, "Platformer");
    SetTargetFPS(60);

    Character perso(screenWidth / 2 - charWidth / 2, screenHeight - charHeight);

    room r;

    Block b(10, 10);

    r.Add(b);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Color{ 255,255,255,255 });

        perso.Update();
        r.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
