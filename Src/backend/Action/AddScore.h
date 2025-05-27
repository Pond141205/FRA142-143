#pragma once

#include "Action.h"

class AddScore: public Action {
public:
    AddScore() {}

    bool Execute(Player& player, Deck& deck) override;

private:
int point_= 10;

};
