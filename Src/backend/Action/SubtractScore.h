#pragma once

#include "Action.h"

// Action/SubtractScore.h
// Declares SubtractScore class, a subclass of Action.
// Subtracts random points from the player's score when executed.

class SubtractScore : public Action {
public:
    SubtractScore() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(9, 16);
        point_ = dist(gen);
    }
   

    bool Execute(Player& player, Deck& deck) override;
    std::string getActionName() const override { return "Subtract Score"; }

private:
    int point_ ;

};
