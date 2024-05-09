//
// Modified by meadowdeath on 28/02/24.
//

#include "../../../../include/Model/Character/Player/Player.h"

#include <utility>
#include <iostream>

Player::Player(char _name[40], int _maxHealth, int _health, int _attack, int _defense, int _speed, int _level, int _currentXP, int _leftOverXP, int _nextLevelXP) :
Character(_name, _maxHealth, _health, _attack, _defense, _speed, _level, CharacterState::IDLE) {
    currentXP = _currentXP;
    leftOverXP = _leftOverXP;
    nextLevelXP = _nextLevelXP;
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