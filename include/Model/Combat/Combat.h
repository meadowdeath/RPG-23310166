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
    void showParticipantsStateDuringCombat();

    // Method to print the character stats
    static void printCharacterStats(Character* character, int width);

    // Method to sort the turns of the participants
    void sortTurns();

    // Method to give the player the option to attack or defend
    void playerTurn();

    // Method to give the enemies the option to attack or defend
    void enemiesTurn();

    // Method that handles player's stats improvements
    void improvePlayerStats();

    // Method that handles what happens when the player wins the combat
    void combatWon();

    // Method that handles what happens when the player loses the combat
    void combatLost();

    // Method to show the combat result
    void handleCombatResult();

public:
    // Constructor to initialize the combat
    Combat(Player* _player, const std::vector<Enemy*>& _enemies);

    // Method to start the combat
    void startCombat();
};


#endif //RPG_COMBAT_H
