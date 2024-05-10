
#include "include/Model/Character/Player/Player.h"
#include "include/Model/Character/Enemy/Enemy.h"
#include "include/Model/Combat/Combat.h"
#include "include/Model/Files/FileHandler.h"
#include <iostream>

int main() {


    // Create a player
    auto *player = new Player();

    // Change the health, attack, defense, and speed values to see how the game changes
    // Create 2 enemies
    char enemy1Name[40] = "Macht of Golden Land";
    char enemy2Name[40] = "Aura, The Guillotine";
    auto *enemy1 = new Enemy(enemy1Name, 120, 120, 12, 4, 8, 1, 49);
    auto *enemy2 = new Enemy(enemy2Name, 50, 50, 5, 2, 7, 1, 50);

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
