#include "Deck.h"
#include "Card.h"

Deck :: Deck(){
        Card question1("Math Challenge", "What is 2 + 2?", {"3", "4", "5", "6"}, 1);
        cards_.push_back(question1);

        Card question2("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question2);

        Card question3("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question3);

        Card question4("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question4);

        Card question5("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question5);

        Card question6("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question6);

        Card question7("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question7);

        Card question8("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question8);

        Card question9("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question9);

        Card question10("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question10);

        Card question11("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question11);

        Card question12("Capital City", "What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2);
        cards_.push_back(question12);

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

    void Deck::shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards_.begin(), cards_.end(), g);
    }

    Card Deck::drawCard() {
        if (cards_.size() != 0) {
            int index = std::rand() % cards_.size();
            Card copy = cards_[index];
            cards_.erase(cards_.begin() + index);
            return copy;
        }
        else{
            return Card("Empty Card", "", {}, 0);
        }
    }

    