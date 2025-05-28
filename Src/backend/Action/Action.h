#pragma once
#include "../Core.h"
#include "../Deck.h"

class Player;
class Deck;

class Action {
public:
    // Action(Player& player) : player_(&player) {}
    Action() {}
    virtual ~Action() {}
    
    virtual bool Execute(Player& player, Deck& deck) {return true; }

    virtual std::string getActionName() const { return "Action"; }
   
};
