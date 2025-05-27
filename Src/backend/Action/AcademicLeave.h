#pragma once

#include "Action.h"


class AcademicLeave : public Action {
public:
    AcademicLeave() {}

    bool Execute(Player& player, Deck& deck) override;
};


