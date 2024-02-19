#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {

    // Change the health, attack, defense, and speed values to see how the game changes

    auto *player = new Player("Frieren, The Slayer", 100, 8, 4, 10);
    auto *enemy = new Enemy("Aura, The Guillotine", 50, 5, 2, 5, 10);
    int encounter = 1;

    while (player->isAlive(true) && enemy->isAlive(true)) {

        cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "Encounter: " << encounter << endl;
        cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << endl;

        cout << player->toString() << endl;

        cout << "+-------------------+" << endl;

        cout << enemy->toString() << endl;

        cout << "=====================" << endl;

        player->doAttack(enemy);
        enemy->doAttack(player);

        encounter++;
    }

    if (player->isAlive(true)) {

        cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "Encounter: " << encounter << endl;
        cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << endl;

        cout << player->toString() << endl;

        cout << "+-------------------+" << endl;

        cout << enemy->toString() << endl;

        cout << "+++++++++++++++++++++" << endl;
        cout << "You Won!" << endl;
        cout << "+++++++++++++++++++++" << endl;

    } else {

        cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "Encounter: " << encounter << endl;
        cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << endl;

        cout << player->toString() << endl;

        cout << "+-------------------+" << endl;

        cout << enemy->toString() << endl;

        cout << "+++++++++++++++++++++" << endl;
        cout << "Game Over!" << endl;
        cout << "+++++++++++++++++++++" << endl;
    }


    delete player;
    delete enemy;
    return 0;
}
