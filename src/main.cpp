#include<raylib.h>

int main()
{
    Color grey= {29,29,27,255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders"); // Initialize window and OpenGL context
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    while(WindowShouldClose() == false){ // Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
        BeginDrawing(); // Setup canvas (framebuffer) to start drawing
        ClearBackground(grey); // Clear the background with the specified color
        EndDrawing();
    }

    CloseWindow();
}
