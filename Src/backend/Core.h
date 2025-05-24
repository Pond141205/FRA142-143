#pragma once

//#include "Board.h"
//#include "Deck.h"
//#include "Action/Action.h"

#include <vector>
#include <memory>
#include <string>




class Player {
public:
    Player(const std::string& name);

    void move(int step);
    void updateScore(int points);
    std::string getName() const;
    int getPosition() const;
    int getScore() const;

    void skipNextTurn();           
    bool shouldSkipTurn() const;  
    void resetSkipTurn();         



private:

    std::string name_;
    int position_;
    int score_;
    bool skip_turn_;
};



class Game{
public:
    Game();

    void setupPlayers(int numPlayers);
    void startGame();
    void nextTurn();
    int rollDice();
    bool checkGameEnd();
    const std::vector<Player>& getPlayers() const;

private:
    std::vector<Player> players_;
    //Board board_;   กำลังสร้างมองข้ามไปก่อน
    //Deck deck_;     กำลังสร้างมองข้ามไปก่อน
    int currentPlayerIndex_;
};



