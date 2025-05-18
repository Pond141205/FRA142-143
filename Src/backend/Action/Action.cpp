#include "Action.h"
#include "AcademicLeave.h"
#include "SubtractScore.h"


bool AcademicLeave::Execute(){

    player_->skipNextTurn();
    std::cout << player_->getName() << " is taking academic leave and will skip the next turn.\n";
    return true;

};

bool SubtractScore::Execute(){

    player_->updateScore(point_);
    std::cout << player_->getName() << "lost" << point_ << " ponits!\n";
    return true;
    
}


