#include "Game.h"
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

