#pragma once

#include "Action.h"



class SubtractScore : public Action {
public:
    SubtractScore() {}
   

    bool Execute(Player& player, Deck& deck) override;
    std::string getActionName() const override { return "Subtract Score"; }

private:
    int point_ = 20;

};
