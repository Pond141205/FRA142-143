#pragma once

#include "Action.h"



class SubtractScore : public Action {
public:
    SubtractScore() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(14, 21);
        point_ = dist(gen);
    }
   

    bool Execute(Player& player, Deck& deck) override;
    std::string getActionName() const override { return "Subtract Score"; }

private:
    int point_ ;

};
