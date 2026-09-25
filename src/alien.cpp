#include "alien.hpp"

Texture2D Alien::alienImages[3] = {};

// Alien types stored in an array
int alienTypes[3] = {1, 2, 3};

const char* alienPaths[3] = {
    "Graphics/alien_1.png",
    "Graphics/alien_2.png",
    "Graphics/alien_3.png"
};

// Linear Search Algorithm
int findAlienIndex(int type)
{
    for (int i = 0; i < 3; i++)
    {
        if (alienTypes[i] == type)
            return i;
    }

    return 0;
}

Alien::Alien(int type, Vector2 position)
{
    this->type = type;
    this->position = position;

    // Find the corresponding alien using Linear Search
    int index = findAlienIndex(type);

    if (alienImages[index].id == 0)
    {
        alienImages[index] = LoadTexture(alienPaths[index]);
    }
}

void Alien::Draw()
{
    int index = findAlienIndex(type);

    DrawTextureV(alienImages[index], position, WHITE);
}

int Alien::GetType()
{
    return type;
}

void Alien::UnloadImages()
{
    // Linear traversal
    for (int i = 0; i < 3; i++)
    {
        UnloadTexture(alienImages[i]);
    }
}

Rectangle Alien::getRect()
{
    int index = findAlienIndex(type);

    return {
        position.x,
        position.y,
        float(alienImages[index].width),
        float(alienImages[index].height)
    };
}

void Alien::Update(int direction)
{
    position.x += direction;
}
