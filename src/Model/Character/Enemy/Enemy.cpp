//
// Modified by meadowdeath on 28/02/24.
//

#include "../../../../include/Model/Character/Enemy/Enemy.h"

#include <utility>
#include <iostream>
#include "../../../../Utils.h"

using namespace combat_utils;

Enemy::Enemy(char _name[40], int _maxHealth, int _health, int _attack, int _defense, int _speed, int _level, int _givenXP) :
Character(_name, _maxHealth, _health, _attack, _defense, _speed, _level, CharacterState::IDLE) {
    givenXP = _givenXP;
}

void Enemy::doAttack(Character *target) {
    if(getState() == CharacterState::ATTACK) {
        // Do the attack if the player is in the attack state
        target->takeDamage(getRolledAttack(attack));
    } else {
        // If the enemy is not in the attack state, Inform to the user.
        std::cout << "The enemy is not in the attack state" << std::endl;
    }
}

void Enemy::doDefend() {
    if(getState() == CharacterState::DEFEND) {
        // Increase the defense by 20% if the player is in the defend state
        getRolledDefense(defense);
    } else {
        // If the enemy is not in the defend state, Inform to the user.
        std::cout << "The enemy is not in the defend state" << std::endl;
    }
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;

    health-= trueDamage;
}

// Getters

int Enemy::getGivenXP() {
    return givenXP;
}

// Setters

void Enemy::setMaxHealth() {
    maxHealth = maxHealth + 10;
}

void Enemy::setAttack() {
    attack = attack + 2;
}

void Enemy::setDefense() {
    defense = defense + 2;
}

void Enemy::setSpeed() {
    speed = speed + 1;
}

void Enemy::setLevel() {
    level = level + 1;
}

void Enemy::setGivenXP() {
    givenXP = givenXP + 10;
}

void Enemy::improveEnemyStats() {
    setMaxHealth();
    restoreHealth();
    setAttack();
    setDefense();
    setSpeed();
    setLevel();
    setGivenXP();
}

// Methods to change the enemy's state

void Enemy::attacking() {
    changeState(CharacterState::ATTACK);
}

void Enemy::defending() {
    changeState(CharacterState::DEFEND);
}

void Enemy::idle() {
    changeState(CharacterState::IDLE);
}