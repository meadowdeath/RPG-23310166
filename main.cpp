
#include "include/Model/Character/Player/Player.h"
#include "include/Model/Character/Enemy/Enemy.h"
#include "include/Model/Combat/Combat.h"
#include "include/Model/Files/FileHandler.h"
#include <iostream>

int main() {


    // Change the health, attack, defense, and speed values to see how the game changes
    // Create a player
    char playerName[40] = "Frieren, The Slayer";
    auto *player = new Player(playerName, 100, 1, 999, 4, 10, 1, 0, 0, 100);

    // Load the player's data if it exists
    player->unserialize("player_data.txt");

    // Create 2 enemies
    char enemy1Name[40] = "Macht of Golden Land";
    char enemy2Name[40] = "Aura, The Guillotine";
    auto *enemy1 = new Enemy(enemy1Name, 120, 120, 12, 4, 8, 1, 49);
    auto *enemy2 = new Enemy(enemy2Name, 50, 50, 5, 2, 7, 1, 50);

    /*
    if (file.fileExists()) {
        file.openForRead();
        if (file.openForRead()) {
            player->deserialize(file);
            file.closeRead();
            std::cout << "Datos del jugador cargados exitosamente.\n";
        } else {
            std::cerr << "Error al abrir el archivo para lectura\n";
            return 1;
        }
    } else {
        file.openForWrite();
        player->serialize(file);
        file.closeWrite();
        std::cout << "Archivo creado con datos predefinidos del jugador.\n";
    }
    */

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
