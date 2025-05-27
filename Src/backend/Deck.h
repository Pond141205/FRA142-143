#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "Core.h"
#include "Card.h"
#include <iostream>

class Card;

class Deck {
private:
    std::vector<Card> deck_;

public:

    Deck();
    
    void setCard();

    void shuffle();

    Card drawCard();
};

