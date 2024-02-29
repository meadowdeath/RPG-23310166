//
// Modified by meadowdeath on 28/02/24.
//

#include "Enemy.h"

#include <utility>
#include <iostream>
#include "../Utils.h"

using namespace combat_utils;

Enemy::Enemy(std::string _name, int _maxHealth, int _health, int _attack, int _defense, int _speed, int _experience) :
Character(std::move(_name), _maxHealth, _health, _attack, _defense, _speed, CharacterState::IDLE) {
    experience = _experience;
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

int Enemy::getExperience() {
    return experience;
}

void Enemy::attacking() {
    changeState(CharacterState::ATTACK);
}

void Enemy::defending() {
    changeState(CharacterState::DEFEND);
}

void Enemy::idle() {
    changeState(CharacterState::IDLE);
}