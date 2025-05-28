#include "Core.h"
#include "Deck.h"
#include "Card.h"
#include "Action/Action.h"
#include "Action/ExtraClass.h"
#include "Action/AcademicLeave.h"
#include "Action/SubtractScore.h"
#include "Action/AddScore.h"
#include <iostream>

/*How to complie "g++ Main.cpp Core.cpp Deck.cpp Card.cpp Action\Action.cpp -o Main
   How to run the program
   1. Open a terminal.
   2. Navigate to the directory where the files are located.
   3. Compile the code using the command:
      g++ Main.cpp Core.cpp Deck.cpp Card.cpp Action/Action.cpp -o Main
   4. Run the program using the command:" 
>> ./Main   */


void printPlayerScores(const std::vector<Player>& players) {
    std::cout << "\nPlayer Scores:\n";
    for (const auto& player : players) {
        std::cout << player.getName() << " : " << player.getScore() << " points, Position: " << player.getPosition() + 1 << "\n";
    }
}

int main() {
    std::cout << "Escape from F: Survive 50 tiles and avoid failing!\n";
    int numPlayers;

    // วนลูปจนกว่าจะกรอกจำนวนผู้เล่นถูกต้อง
    while (true) {
        std::cout << "Enter number of players (2-4): ";
        std::cin >> numPlayers;
        if (numPlayers >= 2 && numPlayers <= 4) {
            break; // ออกจากลูปถ้าถูกต้อง
        }
        std::cout << "Invalid number of players. Please enter between 2 and 4.\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <<== เพิ่มบรรทัดนี้

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

        std::cout << "\nPlayer " << currentPlayer.getName() << "'s turn.\n";
        std::cout << "Roll Dice (y), Restart (r), Quit (q): ";
        char option;
        std::cin >> option;

        if (option == 'q') {
            std::cout << "Quitting game...\n";
            break;
        } else if (option == 'r') {
            std::cout << "Restarting game...\n";
            return main();
        } else if (option == 'y') {
            int diceRoll = game.rollDice();
            std::cout << "Dice rolled: " << diceRoll << "\n";
            currentPlayer.move(diceRoll);

            // Check if reached the last tile
            if (currentPlayer.getPosition() >= 49) {
                std::cout << "Player " << currentPlayer.getName() << " reached the last tile!\n";
                gameOver = true;
            } else {
                std::cout << "Player " << currentPlayer.getName() << " moves to tile " << currentPlayer.getPosition() + 1 << "\n";
            }

            
            if (board.getTile(currentPlayer.getPosition()).hasAction()) {
                std::cout << "You landed on a tile with an action: " 
                          << board.getTile(currentPlayer.getPosition()).getActionName() << "\n";
                
                  // Execute the action on the tile
                  Action* action = board.getTile(currentPlayer.getPosition()).getAction();
                if (action) {
                    Deck deck;
                    if (action->Execute(currentPlayer, deck)) {
                        std::cout << "Action executed successfully.\n";
                    } else {
                        std::cout << "Action execution failed.\n";
                    }
                }
               
            }
            
            


            // Check F
            if (currentPlayer.getScore() <= 0) {
                std::cout << "Player " << currentPlayer.getName() << " has dropped to 0 points.\n";
                
            }

            board.updatePlayersOnTiles(game.getPlayers());

            #ifdef _WIN32
               system("cls");
            #else
               system("clear");
            #endif

            board.printBoard();
            printPlayerScores(game.getPlayers());

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
    const auto& finalPlayers = game.getPlayers(); // <== เปลี่ยนชื่อ
    int maxPoints = -9999;
    std::string winner;
    for (const auto& p : finalPlayers) {
        if (p.getScore() > maxPoints) {
            maxPoints = p.getScore();
            winner = p.getName();
        }
    }
    std::cout << "Winner is " << winner << " with " << maxPoints << " points!\n";
    return 0;
}
