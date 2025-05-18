#include "Core.h"
#include <cstdlib>   //  rand()
#include <ctime>     //  srand()
#include <iostream>

Game::Game() : currentPlayerIndex_(0) {
    std::srand(std::time(nullptr)); // seed random
}

void Game::setupPlayers(int numPlayers){

    for (int i = 0; i < numPlayers; ++i){
        std::string name;
        std::cout << "Enter name" << (i + 1) << ": ";
        std::cin >> name;

        Player newPlayer(name);
        players_.push_back(newPlayer);
    }

    // for (int i = 0; i < players_.size(); ++i){
    //      std::cout << "Player " << (i + 1) << ": " << players_[i].getName() << std::endl;
    // }
}


void Game::startGame() {
    // check players size 
    if (players_.size() < 2 || players_.size() > 4) {
        std::cerr << "Needed at least 2 Players.\n";
        return;
    }
    std::cout << "Game Start!\n";
}

void Game::nextTurn() {
    currentPlayerIndex_ = (currentPlayerIndex_ + 1) % players_.size();
}

int Game::rollDice() {
    return rand() % 6 + 1; // dice roll random 1-6
}

bool Game::checkGameEnd() {
    // check position if all player at position = 50 else game continue 
    for (const auto& p : players_) { 
        if (p.getPosition() < 50) return false;
    }
    return true;
}

const std::vector<Player>& Game::getPlayers() const{
    return players_;
}




Player::Player(const std::string& name)
    : name_(name), position_(0), score_(100), skip_turn_(false) {}

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

void Player::skipNextTurn() {
    skip_turn_ = true;
}

bool Player::shouldSkipTurn() const {
    return skip_turn_;
}

void Player::resetSkipTurn() {
    skip_turn_ = false;
}

