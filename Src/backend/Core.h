#pragma once

//#include "Board.h"
#include "Action/Action.h"

#include <vector>
#include <memory>
#include <string>

class Deck; // Forward declaration
class Card; // Forward declaration
class Action;


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

    Card drawCard();

    int rollDice();
    bool checkGameEnd();
    const std::vector<Player>& getPlayers() const;

private:
    std::vector<Player> players_;
    //Board board_;   
    Deck* deck_;     
    int currentPlayerIndex_;
};



class tile {
public:
    tile(int index, Action* action) : index_(index), action_(action){}
    
    void triggerAction(Player& player, Deck& deck);

    int getIndex() const { return index_; }

    // Action getAction() const { return action_; }

    // void setAction(const Action& action) { action_ = action; }

    bool hasAction() const ;

private:
    int index_;
    Action* action_;;
    
};


class Board {
public:
    Board();
    
    void printBoard() const;
        
    int getSize() const { return size_; };

private:
    int size_ = 50; // Example size, can be adjusted
    std::vector<tile> tiles_; // Vector of tiles on the board
};


