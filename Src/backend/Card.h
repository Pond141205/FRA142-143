#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Deck.h"

class Player; // Forward declaration

class Card {

public:
    Card(const std::string& des, const std::string& q, const std::vector<std::string>& ch, int corr);
    
    void affect(Player& player);

    const std::string& getDescription() const { return description_; }

private:
    std::vector<Card> deck_;
    std::string description_;
    std::string question_;
    std::vector<std::string> choices_;
    int correct_;
    int increase_ = 5;
    int decrease_ = 10;

};