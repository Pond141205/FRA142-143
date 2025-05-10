#pragma once
#include "Game.h"

#include <String>


class Player {
public:
    Player(const std::string& name);

    void move(int step);
    void updateScore(int points);
    int getPosition() const;
    int getScore() const;


private:

    std::string name_;
    int position_;
    int score_;
};