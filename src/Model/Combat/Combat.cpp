//
// Created by meadowdeath on 28/02/2024.
//

#include "../../../include/Model/Combat/Combat.h"
#include <algorithm>
#include <iostream>

Combat::Combat(Player* _player, const std::vector<Enemy*>& _enemies) : player(_player), enemies(_enemies) {}

void Combat::showParticipantsState() {
    // Show the current state of the participants
    std::cout << "The current state of the participants is: " << std::endl;

    std::cout << "+-------------------+" << std::endl;
    std::cout << player->showStats() << std::endl;
    std::cout << "+-------------------+" << std::endl;
    for (auto& enemy : enemies) {
        std::cout << enemy->showStats() << std::endl;
        std::cout << "+-------------------+" << std::endl;
    }
}

void Combat::sortTurns() {
    // Order the turns of the participants
    std::vector<Character*> combatants;
    int combatParticipants = 0;
    combatants.push_back(player);
    for (auto& enemy : enemies) {
        combatants.push_back(enemy);
    }
    std::sort(combatants.begin(), combatants.end(), [](Character* a, Character* b) {
        return a->getSpeed() > b->getSpeed();
    });

    std::cout << "The order of the turns of the combat based in 'speed' is: " << std::endl;
    for (auto& combatant : combatants) {
        combatParticipants++;
        std::cout << combatParticipants <<". " << combatant->getName();
        if(combatant->getName() == player->getName()){
            std::cout << " (Player)" << std::endl;
        } else {
            std::cout << " (Enemy)" << std::endl;
        }
    }

    showParticipantsState(); // Show the current state of the participants

}

void Combat::playerTurn() {
    int playerOption;

    std::cout << "Player's turn" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Defend" << std::endl;
    std::cout << "Select an option: ";
    std::cin >> playerOption;

    while(playerOption != 1 && playerOption != 2){
        std::cout << "Invalid option, please select a valid option: ";
        std::cin >> playerOption;
    }

    if(playerOption == 1){
        if(player->getState() != CharacterState::ATTACK){
            player->attacking(); // Change the state of the player to attack
        }
        // The player decides what enemy to attack
        int enemyOption;
        std::cout << "Select the enemy to attack: " << std::endl;
        // If an ememy is dead, then the player can't attack it, so we remove it from the list
        for (int i = 0; i < enemies.size(); i++) {
            if(enemies[i]->getHealth() <= 0){
                enemies.erase(enemies.begin() + i);
            }
            std::cout << i+1 << ". " << enemies[i]->getName() << std::endl;
        }
        std::cout << "Select an option: ";
        std::cin >> enemyOption;
        while(enemyOption < 1 || enemyOption > enemies.size()){
            std::cout << "Invalid option, please select a valid option: ";
            std::cin >> enemyOption;
        }
        player->doAttack(enemies[enemyOption-1]);
        std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
        std::cout << "The player attacks the enemy " << enemies[enemyOption-1]->getName() << std::endl;

        // If the enemy dies, we show a message
        if(enemies[enemyOption-1]->getHealth() <= 0){
            std::cout << "The enemy " << enemies[enemyOption-1]->getName() << " has died!" << std::endl;
            std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
        }

        if(enemies[enemyOption-1]->getState() == CharacterState::DEFEND){
            std::cout << "The enemy " << enemies[enemyOption-1]->getName() << " is defending..." << std::endl;
            std::cout << "The enemy's amor increases 20%." << std::endl;
            std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
            enemies[enemyOption-1]->idle();
        } else {
            std::cout << "The enemy " << enemies[enemyOption-1]->getName() << " is not defending..." << std::endl;
            std::cout << "The enemy's amor does not increase." << std::endl;
            std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
        }
    } else if (playerOption == 2){
        if(player->getState() != CharacterState::DEFEND && player->getState() != CharacterState::ATTACK){
            player->defending();
            player->doDefend();
            std::cout << "The player " << player->getName() << " is defending... " << std::endl;
            std::cout << "The player's amor increases 20%." << std::endl;
            std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
        } else {
            player->defending();
            player->doDefend();
            std::cout << "The player " << player->getName() << " is already defending... " << std::endl;
            std::cout << "The player's amor does not increase." << std::endl;
            std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
        }
    }

    showParticipantsState(); // Show the current state of the participants
}

void Combat::enemiesTurn() {
    // Enemies logic. First we check every enemy if they can attack the player

    for(auto& enemy : enemies){
        // If the enemy is in the idle state, then the enemy will attack
        if(enemy->getState() == CharacterState::IDLE || enemy->getState() == CharacterState::ATTACK && enemy->getHealth() > 0){
            enemy->attacking(); // Change the state of the enemy to attack
            enemy->doAttack(player);
            std::cout << "The enemy " << enemy->getName() << " attacks the player" << std::endl;
            if(player->getState() == CharacterState::DEFEND){
                std::cout << "The player " << player->getName() << " is defending..." << std::endl;
                std::cout << "The player's amor increases 20%." << std::endl;
                std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
                player->idle();
            } else {
                std::cout << "The player " << player->getName() << " is being attacked..." << std::endl;
                std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
            }
        // If enemy's health is > 15% of the max health, then the enemy will defend
        } else if(enemy->getHealth() < 0.15 * enemy->getMaxHealth() && enemy->getHealth() > 0){
            if(enemy->getState() != CharacterState::DEFEND){
            enemy->defending(); // Change the state of the enemy to defend
            enemy->doDefend();
            std::cout << "The enemy " << enemy->getName() << " is defending..." << std::endl;
                std::cout << "The enemy's amor increases 'considerably'." << std::endl;
                std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
            } else {
                std::cout << "The enemy " << enemy->getName() << " is already defending." << std::endl;
                std::cout << "The enemy's amor does not increase." << std::endl;
                std::cout << "^^^^^^^^^^^^^^^^^^^^^" << std::endl;
            }
        }
    }

    showParticipantsState(); // Show the current state of the participants
}

void Combat::handleCombatResult() {
    if(player->getHealth() > 0 && std::all_of(enemies.begin(), enemies.end(), [](Enemy* i){return i->getHealth() <= 0;}) ){
        std::cout << "+++++++++++++++++++++" << std::endl;
        std::cout << "The player " << player->getName() << " has won the combat!" << std::endl;
        std::cout << "+++++++++++++++++++++" << std::endl;
        exit(0);
    } else if (player->getHealth() <= 0 && std::any_of(enemies.begin(), enemies.end(), [](Enemy* i){return i->getHealth() > 0;})){
        std::cout << "+++++++++++++++++++++" << std::endl;
        std::cout << "The player " << player->getName() << " has lost the combat!" << std::endl;
        std::cout << "+++++++++++++++++++++" << std::endl;
        exit(0);
    } else{
        std::cout << "+++++++++++++++++++++" << std::endl;
        std::cout << "The combat hasn't ended yet!" << std::endl;
        std::cout << "+++++++++++++++++++++" << std::endl;
    }
}

void Combat::startCombat() {

    int playerOption;
    std::cout << "You have found some enemies, wanna fight?" << std::endl;
    std::cout << "1. Yes." << std::endl;
    std::cout << "2. No." << std::endl;
    std::cout << "Select an option: ";
    std::cin >> playerOption;

    while(playerOption != 1 && playerOption != 2){
        std::cout << "Invalid option, please select a valid option: ";
        std::cin >> playerOption;
    }

    if(playerOption == 1){
        int encounterCount = 0;
        std::cout << "You have chosen to fight!" << std::endl;
        sortTurns(); // Order the turns of the participants
        // Put Enemies's health in a vector
        std::vector<int> enemiesHealth;
        for(auto& enemy : enemies){
            enemiesHealth.push_back(enemy->getHealth());
        }
        // Do the combat while the player is alive and at least one enemy is alive
        while(player->getHealth() > 0 || std::any_of(enemiesHealth.begin(), enemiesHealth.end(), [](int i){return i > 0;})){
            encounterCount++;

            std::cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
            std::cout << "Encounter " << encounterCount << std::endl;
            std::cout <<"%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
            playerTurn();
            enemiesTurn();
            handleCombatResult(); // Show the combat result
        }
    } else {
        std::cout << "You have chosen to run away" << std::endl;
        // Exit the program
        exit(0);
    }
}
