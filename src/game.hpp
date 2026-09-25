#pragma once
#include"spaceship.hpp"
#include"obstacle.hpp"

class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
    private:
        std::vector<Obstacle> CreateObstacles();
        void DeleteInactiveLasers();
        Spaceship spaceship;
        std::vector<Obstacle> obstacles;
};