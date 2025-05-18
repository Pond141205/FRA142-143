#pragma once

#include "Action.h"



class SubtractScore : public Action {
public:
    SubtractScore(Player& player, int point) : Action(player), point_(point) {}

    bool Execute() override;

private:
int point_;

};
