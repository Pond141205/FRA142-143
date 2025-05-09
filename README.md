# 🎓 Escape from F - Board Game

**Escape from F** is a turn-based board game inspired by "Snakes and Ladders," where players move across 50 tiles by rolling dice. Each tile contains an action such as gaining/losing points, drawing a special card, or taking an academic leave. The goal is to survive academic obstacles and avoid failing (F)!

---

## 🧩 Game Overview

- 👥 2–4 players
- 🎲 Roll dice and move across 50 tiles
- 🃏 Draw cards on special tiles
- 📈 Start with 100 points, avoid dropping to 0!

---

## 🛠️ Tech Stack

- **Front-end**: Unreal Engine 5 (C++)
- **Back-end**: Game logic in C++
- **Version Control**: Git & GitHub

---

## 📁 Project Structure
EscapeFromF/
├── .gitignore
├── README.md
├── ToDoList.md
├── Src/
| ├── backend/
│   ├── Game.cpp
│   ├── Player.h 
│   ├── Board.h 
│   ├── Tile.h 
│   ├── Action/
│   │ ├── Action.h (Interface)
│   │ ├── AddScore.h 
│   │ ├── SubtractScore.h 
│   │ ├── ExtraClass.h 
│   │ └── AcademicLeave.h 
│   └── Deck/
│   ├── Deck.h 
│   └── Card.h 
| ├── frontend/
└── Docs/
    └──UML Class Diagram.png

## Submission Date
- **Project Submitted** 28/5/68
- **Present Date** 29/5/68