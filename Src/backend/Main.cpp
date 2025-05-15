#include "Game.h"
#include <iostream>

int main() {
    char option;
    do {
        Game game;
        int numPlayers;

        std::cout << "Enter Player numbers: ";
        std::cin >> numPlayers;
        game.setupPlayers(numPlayers);

        game.startGame();

        while (!game.checkGameEnd()) {
            std::cout << "Roll Dice (y), Restart (r), Quit (q): ";
            std::cin >> option;

            if (option == 'y') {
                int roll = game.rollDice();
                std::cout << "Roll Dice: " << roll << std::endl;
                // สมมุติให้ผู้เล่นคนปัจจุบันเดิน
                // คุณต้องมีฟังก์ชันใน Game เช่น getCurrentPlayer() เพื่อเอา player มาขยับ
                // หรือต้องมี player.move(roll) ด้วย

                game.nextTurn(); // ไปผู้เล่นถัดไป
            } else if (option == 'r') {
                std::cout << "Restarting game...\n";
                break; // ออกจาก while เพื่อเริ่มใหม่
            } else if (option == 'q') {
                std::cout << "Quitting game...\n";
                return 0;
            } else {
                std::cout << "Invalid option. Try again.\n";
            }
        }

        if (game.checkGameEnd()) {
            std::cout << "Game Ended!\n";
        }

    } while (option == 'r');

    return 0;
}rd /s /q .git\rebase-merge

