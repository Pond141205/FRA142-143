#pragma once

//#include "Board.h"
#include "Action/Action.h"

#include <vector>
#include <memory>
#include <string>

class Deck; // Forward declaration
class Card; // Forward declaration
class Action; // Forward declaration



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

    // เพิ่ม setter สำหรับ Board หรือการรีเซ็ตค่า
    void setPosition(int pos) { position_ = pos; }
    void setName(const std::string& name) { name_ = name; }
    void setScore(int score) { score_ = score; }

private:
    std::string name_;
    int position_ = 0;
    int score_ = 100;
    bool skip_turn_ = false;
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
    Deck* deck_;     
    int currentPlayerIndex_;
};



class Tile {
public:
    Tile(int index, Action* action) : index_(index), action_(action){}
    
    std::vector<std::string> playersOnTile;

    int getIndex() const { return index_; }

    std::string getActionName() const ;

    Action* getAction() const { return action_; }

    bool hasAction() const ;

private:
    int index_;
    Action* action_;;
    
};


class Board {
public:
    Board();
    void printBoard() const;
    int getSize() const;
    void updatePlayersOnTiles(const std::vector<Player>& players); // เพิ่มบรรทัดนี้
    const Tile& getTile(int index) const { return tiles_[index]; }

private:
    int size_ = 50;
    std::vector<Tile> tiles_;
};

// Core.h
// Declares core classes: Player, Game, Tile, Board.
// - Player: Stores player state (name, position, score, skip turn).
// - Game: Manages players, board, deck, and turn logic.
// - Tile: Represents a board tile, may have an Action.
// - Board: Holds all tiles, manages board display and player positions.


