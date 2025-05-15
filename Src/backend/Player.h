#pragma once

#include <string>


class Player {
public:
    Player(const std::string& name);

    void move(int step);
    void updateScore(int points);
    std::string getName() const;
    int getPosition() const;
    int getScore() const;


private:

    std::string name_;
    int position_;
    int score_;
};