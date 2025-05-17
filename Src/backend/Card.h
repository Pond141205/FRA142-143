#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Core.h"

class Card {

public:
    Card(const std::string& des, const std::string& q, const std::vector<std::string>& ch, int corr, int ptsCorrect = 5, int ptsWrong = -10);
    void affect(Player& player) {}

    const std::string& getDescription() const { return description_; }

private:
    std::string description_;
    std::string question_;
    std::vector<std::string> choices_;
    int correct_;
    int increase_;
    int decrease_;

};