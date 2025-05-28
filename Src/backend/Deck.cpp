#include "Deck.h"



    Card question1("Math Challenge", "What is the derivative of f(x)=x^2+3x+2", {"2x+3", "x^2", "2x+6", "x+3"}, 0);
    Card question2("Science Challenge", "Which one is not a mammal?", {"Dolphin", "Shark", "Sea lions", "walrus"}, 1);
    Card question3("Science Challenge", "Which particle is the smallest in size?", {"Electron", "Atom", "Quark", "Neutron"}, 2);
    Card question4("Science Challenge", "Which of the following is a compound?", {"O2", "H2O", "Au", "Al"}, 1);
    Card question5("Programming Challenge", "The command 'scanf' belongs to which programming language?", {"Python", "Java", "C++", "C"}, 3);
    Card question6("Electronics Challenge", "Which formula is used to calculate the electricity consumption unit for billing?", {"P*t", "(P+220)1000", "(P/1000)*I", "(P*t)/1000"}, 3);
    Card question7("Science Challenge", "Who is the founder of quantum mechanics theory?", {"Albert Einstein", "Galileo Galilei", "Erwin Schrdinger", "Isaac Newton"}, 2);
    Card question8("Art Challenge", "Who is the creator of the artwork 'Starry Night'?", {"Vincent van Gogh", "Leonardo da Vinci", "Claude Monet", "Pablo Picasso"}, 0);
    Card question9("Science Challenge", "Which organ in the human body is primarily responsible for breaking down alcohol?", {"Stomach", "Kidney", "Liver", "Pancreas"}, 2);
    Card question10("Science Challenge", "Which hormone is most commonly released in the body when a person is in love?", {"Oxytocin", "Adrenaline", "Cortisol", "Endorphin"}, 0);
    Card question11("Electronics Challenge", "Which device is used to generate electrical signals with low current?", {"Multimeter", "Oscilloscope", "Power supply", "Function generator"}, 3);
    Card question12("Programming Challenge", "Which programming language is commonly used to create web pages along with HTML and CSS?", {"Java", "JavaScript", "C++", "Python"}, 1);
    
    
    void Deck::setCard() {
        deck_.clear();
        deck_.push_back(question1);
        deck_.push_back(question2);
        deck_.push_back(question3);
        deck_.push_back(question4);
        deck_.push_back(question5);
        deck_.push_back(question6);
        deck_.push_back(question7);
        deck_.push_back(question8);
        deck_.push_back(question9);
        deck_.push_back(question10);
        deck_.push_back(question11);
        deck_.push_back(question12);

        shuffle();
    }
    
    Deck::Deck() {
        setCard();
        // std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }


    void Deck::shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck_.begin(), deck_.end(), g);
    }

    Card Deck::drawCard() {
        if (deck_.size() != 0) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, deck_.size() - 1);

            int index = dist(gen);
            Card copy = deck_[index];
            deck_.erase(deck_.begin() + index);
            // std::cout << "Deck size: " << deck_.size() << std::endl;
            return copy;
        }
        
        
        return Card("Empty Card", "", {}, 0);
    }

    