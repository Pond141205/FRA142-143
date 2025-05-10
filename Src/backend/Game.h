#pragma once

#include "Player.h"
#include "Board.h"
#include "Deck.h"
#include "Action/Action.h"

#include <vector>
#include <memory>


class Game{
public:
    Game();

    void setupPlayers(int numPlayers);
    void startGame();
    void nextTurn();
    int rollDice();
    bool checkGameEnd();

private:
    std::vector<Player> players_;
    //Board board_;   กำลังสร้างมองข้ามไปก่อน
    //Deck deck_;     กำลังสร้างมองข้ามไปก่อน
    int currentPlayerIndex_;
};