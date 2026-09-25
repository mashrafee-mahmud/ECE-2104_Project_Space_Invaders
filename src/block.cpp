#include "block.hpp"

Block::Block(Vector2 position)
{
    this->position = position;
}

void Block::Draw()
{
    int data[4] = {position.x, position.y, 3, 3};

    DrawRectangle(data[0], data[1], data[2], data[3], {243, 216, 63, 255});
}

Rectangle Block::getRect()
{
    int data[4] = {position.x, position.y, 3, 3};

    Rectangle rect;

    // Linear traversal to assign rectangle properties
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            rect.x = data[i];
        else if (i == 1)
            rect.y = data[i];
        else if (i == 2)
            rect.width = data[i];
        else
            rect.height = data[i];
    }

    return rect;
}
