#include "Player.h"

Player::Player(const std::string& name)
    : name_(name), position_(0), score_(100) {}

void Player::move(int steps) {
    position_ += steps;
}

void Player::updateScore(int points) {
    score_ += points;
}

std::string Player::getName() const {
    return name_;
}

int Player::getPosition() const {
    return position_;
}

int Player::getScore() const {
    return score_;
}
