#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        // // Example 12 cards with simple questions
        Card temp("Math Challenge", "What is 2 + 2?", {"3", "4", "5", "6"}, 1);
        cards.push_back(temp);

        Card temp("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(temp);

        Card question3("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question3);

        Card question4("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question4);

        Card question5("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question5);

        Card question6("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question6);

        Card question7("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question7);

        Card question8("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question8);

        Card question9("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question9);

        Card question10("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question10);

        Card question11("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question11);

        Card question12("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards.push_back(question12);

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

    }

    void shuffle() {
        // std::random_device rd;
        // std::mt19937 g(rd());
        // std::shuffle(cards.begin(), cards.end(), g);
    }

    Card drawCard() {
        // if (!cards.empty()) {
        //     int index = std::rand() % cards.size();
        //     Card c = cards[index];
        //     cards.erase(cards.begin() + index);
        //     return c;
        // }
        // return Card("Empty Card", "", {}, 0);
    }
};