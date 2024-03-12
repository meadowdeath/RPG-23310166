//
// Created by meadowdeath on 28/02/2024.
//

#ifndef RPG_COMBAT_H
#define RPG_COMBAT_H
#include <vector>
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"


class Combat {
private:
    std::vector<Enemy*> enemies;
    Player* player;

    // Method to show the current state of the participants
    void showParticipantsState();

    // Method to sort the turns of the participants
    void sortTurns();

    // Method to give the player the option to attack or defend
    void playerTurn();

    // Method to give the enemies the option to attack or defend
    void enemiesTurn();

    // Method to show the combat result
    void handleCombatResult();

public:
    // Constructor to initialize the combat
    Combat(Player* _player, const std::vector<Enemy*>& _enemies);

    // Method to start the combat
    void startCombat();
};


#endif //RPG_COMBAT_H
