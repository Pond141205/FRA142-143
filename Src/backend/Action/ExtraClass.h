#pragma once

#include "Action.h"
#include "../Core.h"
#include "../Deck.h"

// Action/ExtraClass.h
// Declares ExtraClass class, a subclass of Action.
// When executed, draws a quiz card and asks the player a question.

class ExtraClass : public Action {
public :
    ExtraClass() {}
 
    bool Execute(Player& player , Deck& deck) override;
    std::string getActionName() const override { return "Extra Class"; }
};