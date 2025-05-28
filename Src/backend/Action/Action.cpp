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
    card.affect(player);
    return true;
}

bool AddScore::Execute(Player& player, Deck& deck) {

    
        if (player.getScore() < 100){
            std::cout << player.getName() << " has gained " << point_ << " points.\n";
                player.updateScore(+point_);
        }
        if (player.getScore() == 100){
            std::cout << player.getName() <<" points are limited. + " << 0 << " points." << std::endl;
        } 

        return true;
    }


bool AcademicLeave::Execute(Player& player, Deck& deck){

    player.skipNextTurn();
    std::cout << player.getName() << " is on academic leave and will skip the next turn.\n";
    return true;

}

bool SubtractScore::Execute(Player& player, Deck& deck){

    if (player.getScore() <= 100){
        std::cout << player.getName() << " has lose -" << point_ << " points." << std::endl;
            player.updateScore(-point_);
    }
    if (player.getScore() < point_){
        
        std::cout << player.getName() << " has aren't enough score."  << std::endl;
            player.updateScore(-player.getScore());
    }
    
    return true;
    
}


