//
// Modified by meadowdeath on 28/02/24.
//

#include "../../../../include/Model/Character/Player/Player.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

char playerName[40] = "Frieren, The Slayer";

Player::Player() : Character(playerName, 100, 100, 999, 5, 10, 1, CharacterState::IDLE) {
    currentXP = 0;
    leftOverXP = 0;
    nextLevelXP = 100;
    unserialize("player_data.txt");
}

void Player::doAttack(Character *target) {
    //Verify the state of the player
    if(getState() == CharacterState::ATTACK){
        // Do the attack if the player is in the attack state
        target->takeDamage(attack);
    } else {
        // If the player is not in the attack state, Inform to the user.
        std::cout << "The player is not in the attack state" << std::endl;
    }
}

void Player::doDefend() {
    //Verify the state of the player
    if(getState() == CharacterState::DEFEND){
        // Increase the defense by 20% if the player is in the defend state
        defense * 1.20;
    } else {
        // If the player is not in the defend state, Inform to the user.
        std::cout << "The player is not in the defend state" << std::endl;
    }
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;

    health-= trueDamage;
}

/*
void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }
}*/

// Getters

int Player::getCurrentXP() {
    return currentXP;
}

int Player::getLeftOverXP() {
    return leftOverXP;
}

int Player::getNextLevelXP() {
    return nextLevelXP;
}

// Setters

void Player::setMaxHealth() {
    maxHealth = maxHealth + 10;
}

void Player::setAttack() {
    attack = attack + 2;
}

void Player::setDefense() {
    defense = defense + 2;
}

void Player::setSpeed() {
    speed = speed + 1;
}

void Player::setLevel() {
    level = level + 1;
}

void Player::improvePlayerStats(int chosenStat) {
    switch (chosenStat) {
        case 1:
            setMaxHealth();
            restoreHealth();
            break;
        case 2:
            setAttack();
            break;
        case 3:
            setDefense();
            break;
        case 4:
            setSpeed();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            break;
    }
}

void Player::setCurrentXP(int _currentXP) {
    currentXP = _currentXP;
}

void Player::setLeftOverXP(int _leftOverXP) {
    leftOverXP = _leftOverXP;
}

void Player::setNextLevelXP() {
    nextLevelXP = nextLevelXP + 25;
}

// Methods to change the player's state

void Player::attacking() {
    changeState(CharacterState::ATTACK);
}

void Player::defending() {
    changeState(CharacterState::DEFEND);
}

void Player::idle() {
    changeState(CharacterState::IDLE);
}


// Serialize the player's attributes
void Player::serialize(const char* filename) {
    std::ofstream file(filename); {
        if (file.is_open()) {
            file << name << "|" << maxHealth << "|" << health << "|" << attack << "|"
                 << defense << "|" << speed << "|" << level << "|" << currentXP << "|"
                 << leftOverXP << "|" << nextLevelXP << std::endl;
            file.close();
        } else {
            std::cout << "Error opening file" << std::endl;

        }
    }
}

// Unserialize the player's attributes
    void Player::unserialize(const char *filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
            std::string line;
            int _maxHealth, _health, _attack, _defense, _speed, _level, _currentXP, _leftOverXP, _nextLevelXP;
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            std::getline(iss, token, '|'); // Read name
            size_t length = std::min(token.size(), sizeof(name) - 1); // Determinar la longitud del nombre
            std::memcpy(name, token.c_str(), length); // Copiar el nombre al buffer
            name[length] = '\0';
            iss >> _maxHealth;
            iss.ignore(); // Ignore the comma
            iss >> _health;
            iss.ignore();
            iss >> _attack;
            iss.ignore();
            iss >> _defense;
            iss.ignore();
            iss >> _speed;
            iss.ignore();
            iss >> _level;
            iss.ignore();
            iss >> _currentXP;
            iss.ignore();
            iss >> _leftOverXP;
            iss.ignore();
            iss >> _nextLevelXP;

            maxHealth = _maxHealth;
            health = _health;
            attack = _attack;
            defense = _defense;
            speed = _speed;
            level = _level;
            currentXP = _currentXP;
            leftOverXP = _leftOverXP;
            nextLevelXP = _nextLevelXP;
        } else {
        std::cerr << "Error: Empty file." << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
};