//
// Created by meadowdeath on 28/02/2024.
//

#include "../../../include/Model/Combat/Combat.h"
#include "../../../Tables.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace tables_utils;

Combat::Combat(Player* _player, const std::vector<Enemy*>& _enemies) : player(_player), enemies(_enemies) {}

void Combat::showParticipantsState() {

    // Stats table Begins...

    std::string title = "'Press the number that indicates the action you want to perform.'";
    std::string question = "Start Encounter '1'?";
    std::string option1 = "1. Yes";
    std::string option2 = "2. No";

    int statsMaxWidth = static_cast<int>(std::max({title.length(), question.length(), option1.length(), option2.length()}) + 6);

    printLine(statsMaxWidth);
    printCentered(title, statsMaxWidth);
    printLine(statsMaxWidth);

    std::string playerName = this->player->getName();

    printCentered(playerName, statsMaxWidth);
    printLine(statsMaxWidth);
    printCharacterStats(player, statsMaxWidth);

    for (auto& enemy : enemies) {
        std::string enemyName = enemy->getName();
        printCentered(enemyName, statsMaxWidth);
        printLine(statsMaxWidth);
        printCharacterStats(enemy, statsMaxWidth);
        enemyName.clear();
    }


    printCentered(question, statsMaxWidth);
    printLine(statsMaxWidth);
    std::cout << "| " << std::setw(statsMaxWidth / 2 - 2) << std::left << option1 << " | " << std::setw(statsMaxWidth / 2 - 1) << std::left << option2 << " |" << std::endl;
    printLine(statsMaxWidth);
    std::cout << "" << std::endl;

    // Stats Table Ends...
}

void Combat::showParticipantsStateDuringCombat() {

    // Stats During Combat table Begins...

    std::string title = "'Press the number that indicates the action you want to perform.'";
    std::string result = "The current state of the participants during combat is:";

    int statsMaxWidth = static_cast<int>(std::max({title.length(), result.length()}) + 6);

    printLine(statsMaxWidth);
    printCentered(title, statsMaxWidth);
    printLine(statsMaxWidth);
    printCentered(result, statsMaxWidth);
    printLine(statsMaxWidth);

    std::string playerName = this->player->getName();

    printCentered(playerName, statsMaxWidth);
    printLine(statsMaxWidth);
    printCharacterStats(player, statsMaxWidth);

    for (auto& enemy : enemies) {
        std::string enemyName = enemy->getName();
        printCentered(enemyName, statsMaxWidth);
        printLine(statsMaxWidth);
        printCharacterStats(enemy, statsMaxWidth);
        enemyName.clear();
    }
    std::cout << "" << std::endl;

    // Stats During Combat Table Ends...
}

void Combat::printCharacterStats(Character* character, int maxWidth) {
    std::cout << "|   Max Health   |  Health  |  Attack  |  Defense  |  Speed  |   Level   |" << std::endl;
    tables_utils::printLine(maxWidth);
    std::cout << "|   " << std::setw(13) << std::left << character->getMaxHealth() << "| "
              << std::setw(9) << std::left << character->getHealth() << "| "
              << std::setw(9) << std::left << character->getAttack() << "| "
              << std::setw(10) << std::left << character->getDefense() << "| "
              << std::setw(8) << std::left << character->getSpeed() << "| "
              << std::setw(9) << std::left << character->getLevel() << " |" << std::endl;
    printLine(maxWidth);
}


/*void Combat::sortTurns2() {
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
*/

void Combat::sortTurns() {

    // Order table Begins...

    std::string title = "'Press the number that indicates the action you want to perform.'";
    std::string decision = "You have chosen to fight!";
    std::string order = "The order of the turns of the combat based in 'speed' is:";
    std::string question = "Do you want to check the current state of the participants?";
    std::string option1 = "1. Yes.";
    std::string option2 = "2. No.";

    int orderTableMaxWidth = static_cast<int>(std::max({title.length(), decision.length(), order.length(), question.length(), option1.length(), option2.length()}) + 6);

    printLine(orderTableMaxWidth);
    printCentered(title, orderTableMaxWidth);
    printLine(orderTableMaxWidth);
    printCentered(decision, orderTableMaxWidth);
    printLine(orderTableMaxWidth);
    printCentered(order, orderTableMaxWidth);
    printLine(orderTableMaxWidth);
    int threeColumnWidth = (orderTableMaxWidth) / 3;
    std::cout << "| " << std::setw(threeColumnWidth - 10) << std::left <<"Position" << "| " << std::setw(threeColumnWidth + 8) << std::left << "Name" << "| " << std::setw(threeColumnWidth) << std::left << "Character" << "|" << std::endl;
    tables_utils::printLine(orderTableMaxWidth);

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

    for (auto& combatant : combatants) {
        combatParticipants++;
        std::cout << "| " << std::setw(threeColumnWidth - 10) << std::left << combatParticipants << "| " << std::setw(threeColumnWidth + 8) << std::left << combatant->getName() << "| " << std::setw(threeColumnWidth) << std::left;
        if(combatant->getName() == player->getName()){
            std::cout << "(Player) ";
        } else {
            std::cout << "(Enemy)  ";
        }
        std::cout << "|" << std::endl;
        printLine(orderTableMaxWidth);
    }

    printCentered(question, orderTableMaxWidth);
    printLine(orderTableMaxWidth);
    std::cout << "| " << std::setw(orderTableMaxWidth / 2 - 2) << std::left << option1 << " | " << std::setw(orderTableMaxWidth / 2 - 1) << std::left << option2 << " |" << std::endl;
    printLine(orderTableMaxWidth);
    std::cout << "" << std::endl;

    // Order Table Ends...
}

void Combat::playerTurn() {

    int playerOption;
    std::string turn = "Player's turn";
    std::string optionAttack = "1. Attack";
    std::string optionDefend = "2. Defend";
    int encounterTableMaxWidth = 71;

    printCentered(turn, encounterTableMaxWidth);
    printLine(encounterTableMaxWidth);
    std::cout << "| " << std::setw(encounterTableMaxWidth / 2 - 2) << std::left << optionAttack << " | " << std::setw(encounterTableMaxWidth / 2 - 1) << std::left << optionDefend << " |" << std::endl;
    printLine(encounterTableMaxWidth);
    std::cout << "" << std::endl;

    std::cout << "Select an option: ";
    std::cin >> playerOption;
    std::cout << "" << std::endl;

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
        std::string title = "'Press the number that indicates the action you want to perform.'";
        std::string decision = "Select the enemy to attack:";

        printLine(encounterTableMaxWidth);
        printCentered(title, encounterTableMaxWidth);
        printLine(encounterTableMaxWidth);
        printCentered(decision, encounterTableMaxWidth);
        printLine(encounterTableMaxWidth);

        // If an enemy is dead, then the player can't attack it, so we temporarily remove it from the list
        for (int i = 0; i < enemies.size(); i++) {
            // Copy the enemies vector to a new vector to temporarily remove the defeated enemies
            std::vector<Enemy*> defeatedEnemies;
            if(enemies[i]->getHealth() <= 0){

                std::string enemyName = std::to_string(i+1) + ". " + enemies[i]->getName()+ " (Dead)";
                printCentered(enemyName, encounterTableMaxWidth);
                printLine(encounterTableMaxWidth);
                enemyName.clear();
            } else {
                std::string enemyName = std::to_string(i+1) + ". " + enemies[i]->getName();
                printCentered(enemyName, encounterTableMaxWidth);
                printLine(encounterTableMaxWidth);
                enemyName.clear();
            }
        }
        std::cout << "" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> enemyOption;
        // Check if the enemyOption is valid
        while(enemyOption < 1 || enemyOption > enemies.size()){
            std::cout << "Invalid option, please select a valid option: ";
            std::cin >> enemyOption;
        }
        // Check if the enemy is dead
        while (enemies[enemyOption-1]->getHealth() <= 0){
            std::cout << "The enemy " << enemies[enemyOption-1]->getName() << " is dead, please select another enemy: ";
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


}

void Combat::enemiesTurn() {
    // Enemies logic. First we check every enemy if they can attack the player

    for(auto& enemy : enemies){

        // Generate a random number to determine probability of the enemy attacking or defending.
        srand(time(nullptr));
        int probability = rand() % 100 + 1;
        bool defendDecision = false;
        if(probability >= 30 && probability <= 70){
            defendDecision = true;
        } else {
            defendDecision = false;
        }

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
        // If enemy's health is > 15% of the max health, the enemy has a 40% probability of do defend instead of attack.
        } else if(enemy->getHealth() < 0.15 * enemy->getMaxHealth() && enemy->getHealth() > 0 && defendDecision){
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

    showParticipantsStateDuringCombat(); // Show the current state of the participants during combat
}

void Combat::combatWon() {

    int combatWonOption = 0;
    std::string title = "'Press the number that indicates the action you want to perform.'";
    std::string combatResult = "The player " + player->getName() + " has won the combat!";
    std::string option1 = "1. Go to the next level.";
    std::string option2 = "2. Play again.";
    std::string option3 = "3. Exit the game.";

    int combatWonMaxWidth = static_cast<int>(std::max({title.length(), combatResult.length(), option1.length(), option2.length(), option3.length()}) + 6);

    printLine(combatWonMaxWidth);
    printCentered(title, combatWonMaxWidth);
    printLine(combatWonMaxWidth);
    printCentered(combatResult, combatWonMaxWidth);
    printLine(combatWonMaxWidth);
    std::cout << "| " << std::setw(combatWonMaxWidth / 3 - 1) << std::left << option1 << " | " << std::setw(combatWonMaxWidth / 3 - 4) << std::left << option2 << " | " << std::setw(combatWonMaxWidth / 3 - 2) << std::left << option3 << " |" << std::endl;
    printLine(combatWonMaxWidth);
    std::cout << "" << std::endl;

    std::cout << "Select an option: ";
    std::cin >> combatWonOption;
    std::cout << "" << std::endl;

    while (combatWonOption != 1 && combatWonOption != 2 && combatWonOption != 3){
        std::cout << "Invalid option, please select a valid option: ";
        std::cin >> combatWonOption;
    }

    if (combatWonOption == 1){
        clearConsole();
        // Go to the next level
        std::cout << "" << std::endl;
        std::cout << "The player " << player->getName() << " has reached the next level!" << std::endl;
        std::cout << "" << std::endl;
        // Play new level
        player->restoreHealth();
        for(auto& enemy : enemies){
            enemy->improveStats();
        }
        startCombat();
    } else if (combatWonOption == 2){
        clearConsole();
        // Play again
        player->restoreHealth();
        for(auto& enemy : enemies){
            enemy->restoreHealth();
        }
        startCombat();
    } else {
        // Exit the game
        exit(0);
    }
}

void Combat::combatLost() {

    int combatLostOption = 0;
    std::string title = "'Press the number that indicates the action you want to perform.'";
    std::string combatResult = "The player " + player->getName() + " has lost the combat!";
    std::string option1 = "1. Restart the combat.";
    std::string option2 = "2. Exit the game.";

    int combatLostMaxWidth = static_cast<int>(std::max({title.length(), combatResult.length(), option1.length(), option2.length()}) + 6);

    printLine(combatLostMaxWidth);
    printCentered(title, combatLostMaxWidth);
    printLine(combatLostMaxWidth);
    printCentered(combatResult, combatLostMaxWidth);
    printLine(combatLostMaxWidth);
    std::cout << "| " << std::setw(combatLostMaxWidth / 2 - 2) << std::left << option1 << " | " << std::setw(combatLostMaxWidth / 2 - 1) << std::left << option2 << " |" << std::endl;
    printLine(combatLostMaxWidth);
    std::cout << "" << std::endl;

    std::cout << "Select an option: ";
    std::cin >> combatLostOption;
    std::cout << "" << std::endl;

    while (combatLostOption != 1 && combatLostOption != 2){
        std::cout << "Invalid option, please select a valid option: ";
        std::cin >> combatLostOption;
    }

    if (combatLostOption == 1){
        // restore health of the previous combat
        player->restoreHealth();
        for(auto& enemy : enemies){
            enemy->restoreHealth();
        }
        clearConsole();
        startCombat();
    } else {
        exit(0);
    }
}

void Combat::handleCombatResult() {
    if(player->getHealth() > 0 && std::all_of(enemies.begin(), enemies.end(), [](Enemy* i){return i->getHealth() <= 0;}) ){

        combatWon();

    } else if (player->getHealth() <= 0 && std::any_of(enemies.begin(), enemies.end(), [](Enemy* i){return i->getHealth() > 0;})){

        combatLost();

    } else{
        std::cout << "+++++++++++++++++++++" << std::endl;
        std::cout << "The combat hasn't ended yet!" << std::endl;
        std::cout << "+++++++++++++++++++++" << std::endl;
    }
}

void Combat::startCombat() {

    int playerOption;

    // Welcome table Begins...

    std::string title = "'Press the number that indicates the action you want to perform.'";
    std::string question = "You have found some enemies, wanna fight?";
    std::string option1 = "1. Yes.";
    std::string option2 = "2. No.";

    int maxWidth = static_cast<int>(std::max({title.length(), question.length(), option1.length(), option2.length()}) + 6);

    printLine(maxWidth);
    printCentered(title, maxWidth);
    printLine(maxWidth);
    printCentered(question, maxWidth);
    printLine(maxWidth);
    std::cout << "| " << std::setw(maxWidth / 2 - 2) << std::left << option1 << " | " << std::setw(maxWidth / 2 - 1) << std::left << option2 << " |" << std::endl;
    printLine(maxWidth);
    std::cout << "" << std::endl;

    // Welcome Table Ends...


    std::cout << "Select an option: ";
    std::cin >> playerOption;

    while(playerOption != 1 && playerOption != 2){
        std::cout << "Invalid option, please select a valid option: ";
        std::cin >> playerOption;
    }

    if(playerOption == 1){

        int playerDecision = 0;
        do {
            clearConsole();

            std::cout << "" << std::endl;
            sortTurns(); // Order the turns of the participants

            std::cout << "Select an option: ";
            std::cin >> playerDecision;

            while(playerDecision != 1 && playerDecision != 2){
                std::cout << "Invalid option, please select a valid option: ";
                std::cin >> playerDecision;
            }

            clearConsole();

            if (playerDecision == 1){
                std::cout << "" << std::endl;
                showParticipantsState(); // Show the current state of the participants
                playerDecision = 0;
                std::cout << "Select an option: ";
                std::cin >> playerDecision;

                while(playerDecision != 1 && playerDecision != 2){
                    std::cout << "Invalid option, please select a valid option: ";
                    std::cin >> playerDecision;
                }

                if(playerDecision == 1){
                    clearConsole();
                    break;
                }

                clearConsole();
            } else {
                break;
            }

        } while (playerOption == 1);

        // Put Enemies's health in a vector
        std::vector<int> enemiesHealth;
        int encounterCount = 0;
        enemiesHealth.reserve(enemies.size());
        for(auto& enemy : enemies){
            enemiesHealth.push_back(enemy->getHealth());
        }
        // Do the combat while the player is alive and at least one enemy is alive
        while(player->getHealth() > 0 || std::any_of(enemiesHealth.begin(), enemiesHealth.end(), [](int i){return i > 0;})){
            encounterCount++;

            std::string action = "'Press the number that indicates the action you want to perform.'";
            std::string encounter = "Encounter " + std::to_string(encounterCount);

            int encounterTableMaxWidth = static_cast<int>(std::max({title.length(), encounter.length()}) + 6);

            printLine(encounterTableMaxWidth);
            printCentered(action, encounterTableMaxWidth);
            printLine(encounterTableMaxWidth);
            printCentered(encounter, encounterTableMaxWidth);
            printLine(encounterTableMaxWidth);
            playerTurn();
            std::cout << "" << std::endl;
            enemiesTurn();
            handleCombatResult(); // Show the combat result
            std::cout << "" << std::endl;
        }
    } else {
        std::cout << "" << std::endl;
        std::cout << "You have chosen to run away" << std::endl;
        // Exit the program
        exit(0);
    }
}
