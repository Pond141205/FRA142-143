#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "Core.h"
#include "Card.h"
#include <iostream>

// Deck.h
// Declares Deck class for managing a collection of Card objects.
// Provides methods to set up, shuffle, and draw cards for quiz actions.

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

