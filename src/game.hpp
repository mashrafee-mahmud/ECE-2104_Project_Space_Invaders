#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"

#include <vector>
#include <string>


// =========================
// Binary Search Tree
// =========================

class HighScoreBST {
private:
    struct Node {
        int score;
        Node* left;
        Node* right;

        Node(int value) {
            score = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    void insert(Node*& node, int score);
    void getTopScores(Node* node, std::vector<int>& scores, int limit);
    void deleteTree(Node* node);

public:
    HighScoreBST();
    ~HighScoreBST();

    void Insert(int score);
    std::vector<int> GetTopScores(int limit);
    int GetHighestScore();

    void SaveToFile(const std::string& filename);
    void LoadFromFile(const std::string& filename);
};


class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        bool run;
        int lives;
        int score;
        int highscore;
        Music music;

        // High score BST
        HighScoreBST highScoreTree;

    private:
        void DeleteInactiveLasers();
        std::vector<Obstacle> CreateObstacles();
        std::vector<Alien> CreateAliens();
        void MoveAliens();
        void MoveDownAliens(int distance); 
        void AlienShootLaser();
        void CheckForCollisions();
        void GameOver();
        void Reset();
        void InitGame();
        void checkForHighscore();
        Spaceship spaceship;
        std::vector<Obstacle> obstacles;
        std::vector<Alien> aliens;
        int aliensDirection;
        std::vector<Laser> alienLasers;
        constexpr static float alienLaserShootInterval = 0.35;
        float timeLastAlienFired;
        MysteryShip mysteryship;
        float mysteryShipSpawnInterval;
        float timeLastSpawn;
        Sound explosionSound;
};