// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"
// #include "Card.h"
// #include "Deck.h"

// TEST_CASE("Card constructor and getters work", "[Card]") {
//     std::vector<std::string> choices = {"A", "B", "C", "D"};
//     Card card("Test Category", "Test Question", choices, 2);

//     REQUIRE(card.getDescription() == "Test Category");
//     REQUIRE(card.getQuestion() == "Test Question");
//     REQUIRE(card.getChoices() == choices);
//     // You may need to add a getCorrect() or similar method to Card to test the answer index
// }

// TEST_CASE("Deck initializes and draws cards", "[Deck]") {
//     Deck deck;
//     deck.setCard(); // Make sure this populates the deck

//     // Check that the deck is not empty after initialization
//     REQUIRE(deck.size() > 0);

//     Card card = deck.drawCard();
//     REQUIRE(!card.getDescription().empty());
//     REQUIRE(!card.getQuestion().empty());
// }