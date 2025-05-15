// #include <iostream>
// #include "Card.h"
// #include "Deck.h"
// #include "Player.h"

// int main() {
//     Deck Deck;

//     Player player("Tester");

//     while (true) {
//         Card card = Deck.drawCard();

//         if (card.getDescription() == "Empty Card") {
//             std::cout << "\nNo more cards left.\n";
//             break;
//         }
//         card.affect(player);

//         std::cout << "Current Score: " << player.getScore() << "\n";
//         std::cout << "-----------------------------\n";
//     }

//     std::cout << "\nFinal Score: " << player.getScore() << "\n";
//     std::cout << "Thanks for playing!\n";

//     return 0;
// } ติดบัคเอ๋อๆไรไม่รู้ เดะมาแก้ต่อ