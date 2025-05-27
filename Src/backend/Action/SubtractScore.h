#pragma once

#include "Action.h"



class SubtractScore : public Action {
public:
    SubtractScore() {}
   

    bool Execute(Player& player, Deck& deck) override;

private:
int point_ = 20;

};
