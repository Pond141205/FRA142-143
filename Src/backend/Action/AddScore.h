#pragma once

#include "Action.h"

class AddScore: public Action {
public:
    AddScore() {}

    bool Execute(Player& player, Deck& deck) override;
    std::string getActionName() const override { return "Add Score"; }

private:
    int point_= 10;

};
