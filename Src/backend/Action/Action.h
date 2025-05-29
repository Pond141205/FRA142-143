#pragma once
#include "../Core.h"
#include "../Deck.h"

// Action/Action.h
// Declares abstract Action class (interface) for tile actions.
// All specific actions (AddScore, SubtractScore, ExtraClass, AcademicLeave) inherit from this.
// Defines Execute method to be overridden by derived actions.

class Player;
class Deck;

class Action {
public:
   
    Action() {}
    virtual ~Action() {}
    
    virtual bool Execute(Player& player, Deck& deck) {return true; }

    virtual std::string getActionName() const { return "Action"; }
   
};
