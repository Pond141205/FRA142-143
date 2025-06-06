#pragma once

#include "Action.h"

// Action/AddScore.h
// Declares AddScore class, a subclass of Action.
// Adds random points to the player's score when executed.

class AddScore: public Action {
public:
    AddScore() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(3, 7);
        point_ = dist(gen);
    }

    bool Execute(Player& player, Deck& deck) override;
    std::string getActionName() const override { return "Add Score"; }

private:
    int point_ ;
};
