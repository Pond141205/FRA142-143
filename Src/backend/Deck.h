#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "Card.h"
#include <iostream>

class Card;

class Deck {
private:
    std::vector<Card> cards_;

public:

    Deck(){}

    void shuffle() {}

    Card drawCard() {}
};