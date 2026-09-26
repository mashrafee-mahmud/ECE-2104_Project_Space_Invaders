#include <raylib.h>
#include "game.hpp"
#include <string>
#include <vector>

std::string FormatWithLeadingZeros(int number, int width) {
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
}

int main()
{
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space Invaders");
    InitAudioDevice();

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false) {
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(grey);

        DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 2, yellow);
        DrawLineEx({25, 730}, {775, 730}, 3, yellow);


        game.Draw();
        if(!game.run){

            DrawRectangle(
                100,
                100,
                600,
                580,
                grey
            );

            DrawRectangleLinesEx(
                {100, 100, 600, 580},
                3,
                yellow
            );


            DrawTextEx(
                font,
                "GAME OVER",
                {270, 130},
                45,
                2,
                yellow
            );


            std::string finalScore =
                "SCORE: " +
                FormatWithLeadingZeros(game.score, 5);

            DrawTextEx(
                font,
                finalScore.c_str(),
                {280, 200},
                30,
                2,
                yellow
            );


            DrawTextEx(
                font,
                "   TOP 5 HIGH SCORES",
                {190, 270},
                32,
                2,
                yellow
            );


            // Get top 5 scores from BST
            std::vector<int> topScores =
                game.highScoreTree.GetTopScores(5);


            for(int i = 0; i < topScores.size(); i++)
            {
                std::string rank =
                    std::to_string(i + 1) + ".";

                std::string scoreText =
                    FormatWithLeadingZeros(topScores[i], 5);


                DrawTextEx(
                    font,
                    rank.c_str(),
                    {250.0f, 325.0f + static_cast<float>(i) * 45.0f},
                    28,
                    2,
                    yellow
                );


                DrawTextEx(
                    font,
                    scoreText.c_str(),
                    {450.0f, 325.0f + static_cast<float>(i) * 45.0f},
                    28,
                    2,
                    yellow
                );
            }


            DrawTextEx(
                font,
                "  PRESS ENTER TO PLAY AGAIN",
                {190, 590},
                25,
                2,
                yellow
            );
        }


        float x = 50.0;
        for(int i = 0; i < game.lives; i ++) {
            DrawTextureV(spaceshipImage, {x, 745}, WHITE);
            x += 50;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        DrawTextEx(font, "HIGH-SCORE", {570, 15}, 34, 2, yellow);
        std::string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {655, 40}, 34, 2, yellow);


        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
}