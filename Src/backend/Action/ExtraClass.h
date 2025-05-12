#pragma once

#include "Action.h"
#include "../Player.h"
#include "Deck.h"

class ExtraClass : public Action {
    public :
        void Execute(Player& player , Deck& deck) override {
            Card drawcard = deck.drawCard();

            drawcard.affect(player);
        }
};