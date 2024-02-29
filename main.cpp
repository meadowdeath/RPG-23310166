#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"

int main() {

    // Change the health, attack, defense, and speed values to see how the game changes

    auto *player = new Player("Frieren, The Slayer", 100, 100, 999, 4, 10);

    // Create 2 enemies
    auto *enemy1 = new Enemy("Macht of Golden Land", 120, 120, 12, 4, 8, 10);
    auto *enemy2 = new Enemy("Aura, The Guillotine", 50, 50, 5, 2, 7, 10);

    // Create a vector with the participants
    std::vector<Enemy*> enemies = {enemy1, enemy2};

    // Create the combat
    auto *combat = new Combat(player, enemies);

    // Start the combat
    combat->startCombat();

    delete player;
    delete enemy1;
    delete enemy2;
    delete combat;
    return 0;
}
