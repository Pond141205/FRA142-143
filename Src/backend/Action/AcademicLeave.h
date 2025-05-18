#pragma once

#include "Action.h"


class AcademicLeave : public Action {
public:
    AcademicLeave(Player& player) : Action(player) {}

    bool Execute() override;
};


