#pragma once
#include "Core.h"
#include "Deck.h"

class Action {
public:
    Action(Player& player) : player_(&player) {}

    virtual bool Execute() {return true; }

protected:
    Player* player_;
    
};
