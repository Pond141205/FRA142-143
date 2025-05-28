#include "Card.h"

Card::Card(const std::string& des,
           const std::string& q,
           const std::vector<std::string>& ch,
           int corr)
    : description_(des), question_(q), choices_(ch), correct_(corr) {}

void Card::affect(Player& player) {
        std::cout << "\nCard: " << description_ << std::endl;
        std::cout << question_ << std::endl;
        for (int i = 0; i < choices_.size(); i++) {
            std::cout << i + 1 << ". " << choices_[i] << std::endl;
        }
        std::cout << "Enter your choice : ";
        int answer;
        std::cin >> answer;
        if (answer - 1 == correct_) {
                 if (player.getScore() < 100){
                    std::cout << "Correct! +" << increase_ << " points." << std::endl;
                    player.updateScore(+increase_);
                 }
                 if (player.getScore() == 100){
                     std::cout << "Correct! ... But your points are limited. + " << 0 << " points." << std::endl;
                 } 
        } else {
            std::cout << "Wrong! " << decrease_ << " - points." << std::endl;
            player.updateScore(-decrease_);
        }
    }