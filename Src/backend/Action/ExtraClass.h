#pragma once

#include "Action.h"
#include "../Core.h"
#include "../Deck.h"

class ExtraClass : public Action {
public :
    ExtraClass() {}
 
    bool Execute(Player& player , Deck& deck) override;
    std::string getActionName() const override { return "Extra Class"; }
};