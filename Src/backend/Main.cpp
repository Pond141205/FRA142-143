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







int main() {
    
    // char option;
    // do {
    //     Game game;
    //     int numPlayers;

    //     std::cout << "Enter Player numbers: ";
    //     std::cin >> numPlayers;
    //     game.setupPlayers(numPlayers);

    //     game.startGame();

    //     while (!game.checkGameEnd()) {
    //         std::cout << "Roll Dice (y), Restart (r), Quit (q): ";
    //         std::cin >> option;

    //         if (option == 'y') {
    //             int roll = game.rollDice();
    //             std::cout << "Roll Dice: " << roll << std::endl;
    //             // 
    //             //  Game  getCurrentPlayer()  player 
    //             //  player.move(roll)

    //             game.nextTurn(); // 
    //         } else if (option == 'r') {
    //             std::cout << "Restarting game...\n";
    //             break; // while 
    //         } else if (option == 'q') {
    //             std::cout << "Quitting game...\n";
    //             return 0;
    //         } else {
    //             std::cout << "Invalid option. Try again.\n";
    //         }
    //     }

    //     if (game.checkGameEnd()) {
    //         std::cout << "Game Ended!\n";
    //     }

    // } while (option == 'r');

      Action* action = new ExtraClass();
      action->Execute(*(new Player("Player1")), *(new Deck()));
      delete action; // Clean up dynamically allocated memory


    return 0;
}

