#include "Player.h"

Player::Player(const std::string& name)
    : name_(name), position_(0), score_(0) {}

void Player::move(int steps) {
    position_ += steps;
}

void Player::updateScore(int points) {
    score_ += points;
}

int Player::getPosition() const {
    return position_;
}

int Player::getScore() const {
    return score_;
}
