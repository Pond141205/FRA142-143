#  Escape from F - Terminal Board Game

##  Program Documentation

### Main Files & Folders

#### `Src/backend/`
- **Main.cpp**  
  Entry point of the game. Handles game initialization, main loop, and user interaction.

- **Core.h / Core.cpp**  
  Contains core game logic and main classes:
  - `Game`: Manages players, turns, and game flow.
  - `Player`: Represents each player, their score, position, and state.
  - `Board`: Represents the game board and its tiles.
  - `tile`: Represents each tile on the board, which may have an action.

#### `Src/backend/Action/`
- **Action.h**  
  Abstract base class (interface) for all actions that can occur on a tile.
- **AddScore.h / AddScore.cpp**  
  Implements an action that increases a player's score.
- **SubtractScore.h / SubtractScore.cpp**  
  Implements an action that decreases a player's score.
- **ExtraClass.h / ExtraClass.cpp**  
  Implements an action where a player draws a special card.
- **AcademicLeave.h / AcademicLeave.cpp**  
  Implements an action that causes a player to skip their next turn.

#### `Src/backend/Deck/`
- **Deck.h / Deck.cpp**  
  Manages a deck of cards, including shuffling and drawing.
- **Card.h / Card.cpp**  
  Represents a question card, including its category, question, choices, and correct answer.


#### `Docs/`
- **UML Class Diagram.png**  
  Visual representation of the class structure and relationships.

---

### How the Program Works

1. **Game Initialization:**  
   The game starts in `Main.cpp`, which creates a `Game` object and sets up players and the board.

2. **Gameplay Loop:**  
   Players take turns rolling dice and moving across the board.  
   When landing on a tile, the tile may trigger an action (e.g., add/subtract score, draw a card, skip turn).

3. **Actions & Cards:**  
   Actions are implemented as subclasses of `Action`.  
   Some actions (like `ExtraClass`) interact with the deck of cards, presenting questions to the player.

4. **Game End:**  
   The game ends when a player reaches the final tile or loses all points.

---

### File Relationships

- `Main.cpp` uses `Core.h` for the main game logic.
- `Core.h` uses `Action/Action.h` for tile actions and `Deck/Deck.h` for card management.
- Each action (e.g., `AddScore`, `AcademicLeave`) inherits from `Action`.
- `Deck` manages `Card` objects, which are used in some actions.

---

##  Functional Summary

### Functions (Method-Level Behaviors)

#### Game Flow Functions
- `Game::start()` – Initializes players, board, and game state.
- `Game::playTurn()` – Controls the main turn logic: dice roll, movement, and action.
- `Player::move(int steps)` – Moves the player by a given number of steps.
- `Game::checkGameEnd()` – Checks for game end conditions (win/loss).

#### Tile Action Functions (from `Action`)
- `AddScore::execute(Player* p)` – Increases the player’s score.
- `SubtractScore::execute(Player* p)` – Decreases the player’s score.
- `ExtraClass::execute(Player* p)` – Draws a card and asks a question.
- `AcademicLeave::execute(Player* p)` – Skips the player’s next turn.

#### Card & Deck Functions
- `Deck::drawCard()` – Randomly draws a card from the deck.
- `Deck::setCard()` – Prepare card to Deck.
- `Deck::shuffle()` – Shuffle card in Deck.
- `Card::affect(Player& player)` – Apply affect to players.

---

###  Non-Function Components (Design/Structure/Objects)

- **Object-Oriented Design:**  
  - Uses classes to represent game entities (`Game`, `Player`, `Board`, `Tile`, etc.).
  - Supports modularity and reuse.

- **Polymorphism via Inheritance:**  
  - All tile actions inherit from the abstract `Action` interface.
  - Enables different behaviors depending on tile type.

- **Encapsulation:**  
  - Each class handles its own data (e.g., `Player` manages score/position).

- **Deck Management System:**  
  - `Deck` manages random shuffling and drawing of `Card` objects.
  - `Card` contains multiple-choice questions and answer logic.

- **Tile System:**  
  - Board consists of tiles that can trigger events or actions when players land on them.

---
## 🕹️ How to Play

1. **Start the Game**
   - Run the game with: `./main`
   - Enter the number of players (2–4).
   - Input each player’s name one by one and press Enter.

2. **Game Board**
   - The board is 10x5 (50 tiles in total).
   - Each tile has an effect such as:
     - Gain points.
     - Lose points.
     - Answer a quiz question.
     - Skip next turn.

3. **In-Game Commands**
   When it’s a player’s turn, the following options will appear:
- Press `y` to roll the dice and continue.
- Press `r` to restart the game.
- Press `q` to quit the game.

4. **Game Rules**
- Players move according to the dice roll.
- Landing on certain tiles will trigger special actions or events.
- Quiz questions reward correct answers with points.
- **The game only ends when all players reach the final tile** (Tile #50).
- The winner is the player with the **highest score** at the end.

---
## ⚙️ How to Compile & Run

```bash
g++ Src/backend/*.cpp Src/backend/Action/*.cpp Src/backend/Deck/*.cpp -o main
./main


 **Project Structure**

- `.gitignore`
- `README.md`
- `ToDoList.md`
- `Src/`
  - `backend/`
    - `Main.cpp`
    - `Core.h`
    - `Core.cpp`
    - `Action/`
      - `Action.h` – Interface
      - `AddScore.h`
      - `SubtractScore.h`
      - `ExtraClass.h`
      - `AcademicLeave.h`
    - `Deck/`
      - `Deck.h`
      - `Card.h`
      - `Deck.cpp`
      - `Card.cpp`
  - `frontend/`
- `Docs/`
  - `UML Class Diagram.png`
