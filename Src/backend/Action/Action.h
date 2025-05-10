#pragma once

class Player;  // Forward declaration เพื่อหลีกเลี่ยง include ซ้ำ

class Action {
public:
    virtual void Execute(Player& player) = 0;
    virtual ~Action() = default;
};
