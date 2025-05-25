#pragma once

#include "Action.h"
#include "Core.h"
#include "Deck.h"

class ExtraClass : public Action {
    public :
        void Execute(Player& player , Deck& deck) {
            // Card drawcard = deck.drawCard();

            // drawcard.affect(player);
        }
};