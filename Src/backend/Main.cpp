#include "Core.h"
#include "Deck.h"
#include "Card.h"
#include "Action/Action.h"
#include "Action/ExtraClass.h"
#include "Action/AcademicLeave.h"
#include "Action/SubtractScore.h"
#include "Action/AddScore.h"
#include <iostream>
#include <chrono>
#include <thread>

/*How to complie "g++ Main.cpp Core.cpp Deck.cpp Card.cpp Action\Action.cpp -o Main
   How to run the program
   1. Open a terminal.
   2. Navigate to the directory where the files are located.
   3. Compile the code using the command:
      g++ Main.cpp Core.cpp Deck.cpp Card.cpp Action/Action.cpp -o Main
   4. Run the program using the command:" 
>> ./Main   */


// Main.cpp
// Entry point for "Escape from F" terminal board game.
// Handles game initialization, player setup, main game loop, user input, and game flow.
// Interacts with Game, Board, Player, and Action classes to run the game.


void printPlayerScores(const std::vector<Player>& players) {
    std::cout << "\nPlayer Scores:\n";
    for (const auto& player : players) {
        std::cout << player.getName() << " : " << player.getScore() << " points, Position: " << player.getPosition() + 1 << "\n";
    }
}

bool allPlayersAtLastTile(const std::vector<Player>& players) {
    for (const auto& p : players) {
        if (p.getPosition() < 49) return false;
    }
    return true;
}

int main() {
    std::cout << "Escape from F: Survive 50 tiles and avoid failing!\n";
    int numPlayers;

    // วนลูปจนกว่าจะกรอกจำนวนผู้เล่นถูกต้อง
    while (true) {
        std::cout << "Enter number of players (2-4): ";
        std::cin >> numPlayers;
            if (std::cin.fail()) {
                std::cin.clear(); // clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter a number between 2 and 4.\n";
                continue;
            }
            if (numPlayers >= 2 && numPlayers <= 4) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear rest of line
                break;
            }
            std::cout << "Invalid number of players. Please enter between 2 and 4.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear rest of line
    }
    Game game;
    game.setupPlayers(numPlayers);

    // สุ่มลำดับผู้เล่น
    auto& players = const_cast<std::vector<Player>&>(game.getPlayers());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(players.begin(), players.end(), g);

    game.startGame();

    // สร้างกระดานและแสดงตารางหลังเริ่มเกม
    Board board;
    board.printBoard();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    bool gameOver = false;
    int turn = 0;
    while (!gameOver) {
        Player& currentPlayer = players[turn % numPlayers];
        if (currentPlayer.shouldSkipTurn()) {
            std::cout << "Player " << currentPlayer.getName() << " is skipping this turn.\n";
            currentPlayer.resetSkipTurn();
            game.nextTurn();
            ++turn; // เพิ่มตรงนี้เพื่อข้ามเทิร์น
            continue;
        }

        if(currentPlayer.getPosition() == 49) {
            std::cout << "Player " << currentPlayer.getName() << " has already reached the last tile.\n";
            game.nextTurn();
            ++turn; // เพิ่มตรงนี้เพื่อข้ามเทิร์น
            continue;
        }

        std::cout << "\nPlayer " << currentPlayer.getName() << "'s turn.\n";
        std::cout << "Roll Dice (y), Restart (r), Quit (q): ";
        char option;
        std::cin >> option;

        if(std::cin.fail()) {
            std::cin.clear(); // clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter 'y', 'r', or 'q'.\n";
            continue;
        }   

        if (option == 'q') {
            std::cout << "Quitting game...\n";
            break;
        } else if (option == 'r') {
            #ifdef _WIN32
               system("cls");
            #else
               system("clear");
            #endif
            std::cout << "Restarting game...\n";
            return main();
        } else if (option == 'y') {
            int diceRoll = game.rollDice();
            std::cout << "\n Dice rolled: " << diceRoll << "\n";
            currentPlayer.move(diceRoll);

            // ถ้าข้ามช่อง 50 ให้ไปหยุดที่ 50
            if (currentPlayer.getPosition() > 49) {
                currentPlayer.setPosition(49);
            }

            if (currentPlayer.getPosition() >= 49) {
                std::cout << "Player " << currentPlayer.getName() << " reached the last tile!\n";
            } else {
                std::cout << "\n";
                std::cout << "Player " << currentPlayer.getName() << " moves to tile " << currentPlayer.getPosition() + 1 << "\n";
            }

            
            if (board.getTile(currentPlayer.getPosition()).hasAction()) {
                std::cout << "\n You landed on a tile with an action: " 
                          << board.getTile(currentPlayer.getPosition()).getActionName() << "\n";
                
                  // Execute the action on the tile
                  Action* action = board.getTile(currentPlayer.getPosition()).getAction();
                if (action) {
                    Deck deck;
                    if (action->Execute(currentPlayer, deck)) {
                        std::cout << "Action executed successfully: " ;
                    } else {
                        std::cout << "Action execution failed.\n";
                    } 
                }
               
            }else {
                std::cout << "\n No action on this tile.\n";
            }
            
            


            // Check F
            if (currentPlayer.getScore() <= 0) {
                std::cout << "Player " << currentPlayer.getName() << " has dropped to 0 points.\n";
                
            }

            board.updatePlayersOnTiles(game.getPlayers());
            std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 seconds
            #ifdef _WIN32
               system("cls");
            #else
               system("clear");
            #endif
            board.printBoard();

            printPlayerScores(game.getPlayers());

            // หลังจบเทิร์นนี้ เช็กว่าทุกคนถึงช่อง 50 หรือยัง
            if (allPlayersAtLastTile(players)) {
                break; // ออกจากลูปเพื่อจบเกม
            }

            game.nextTurn();
            ++turn; // เพิ่มตรงนี้
        } else {
            std::cout << "Invalid option. Please try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }

    std::cout << "\nGame finished!\n";
    // หาผู้ชนะ (คะแนนมากสุด)
    const auto& finalPlayers = game.getPlayers(); 
    int maxPoints = -9999;
    std::string winner;
    for (const auto& p : finalPlayers) {
        if (p.getScore() > maxPoints) {
            maxPoints = p.getScore();
            winner = p.getName();
        }
    }
}

