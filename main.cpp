#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {

    // Change the health, attack, defense, and speed values to see how the game changes

    auto *player = new Player("Frieren, The Slayer", 100, 8, 4, 10);
    auto *enemy = new Enemy("Aura, The Guillotine", 50, 5, 2, 5, 10);


    delete player;
    delete enemy;
    return 0;
}
