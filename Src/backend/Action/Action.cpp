#include "Action.h"
#include "AcademicLeave.h"
#include "SubtractScore.h"
#include "ExtraClass.h"
#include "AddScore.h"



bool ExtraClass::Execute(Player& player , Deck& deck) {
    Deck deck_;
    deck.setCard();
    deck.shuffle();
    Card card = deck.drawCard();
    std::cout << "Extra Class" << std::endl;
    card.affect(player);
    return true;
}

bool AddScore::Execute(Player& player, Deck& deck) {

    std::cout << player.getName() << " has gained " << point_ << " points.\n";
    player.updateScore(+point_);
    return true;

}

bool AcademicLeave::Execute(Player& player, Deck& deck){

    player.skipNextTurn();
    std::cout << player.getName() << " is on academic leave and will skip the next turn.\n";
    return true;

};

bool SubtractScore::Execute(Player& player, Deck& deck){

    std::cout << player.getName() << " has lost " << point_ << " points.\n";
    player.updateScore(-point_);
    return true;
    
}


