#pragma once

#include "Action.h"


// Action/AcademicLeave.h
// Declares AcademicLeave class, a subclass of Action.
// When executed, causes the player to skip their next turn.

class AcademicLeave : public Action {
public:
    AcademicLeave() {}

    bool Execute(Player& player, Deck& deck) override;

    std::string getActionName() const override { return "Academic Leave";}
};


