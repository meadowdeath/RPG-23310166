//
// Modified by meadowdeath on 28/02/24.
//

#include "../../../include/Model/Character/Character.h"

#include <utility>
#include <cstring>

Character::Character(char _name[40], int _maxHealth, int _health, int _attack, int _defense, int _speed, CharacterState _currentState) {
    strcpy(name, _name);
    maxHealth = _maxHealth;
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    currentState = _currentState;

}

CharacterState Character::getState() {
    return currentState;
}

void Character::changeState(CharacterState newState) {
    currentState = newState;
}

std::string Character::getName() {
    return name;
}

int Character::getMaxHealth() {
    return maxHealth;

}

int Character::getHealth() {
    if (health < 0) {
        return 0;
    } else {
        return health;
    }
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

std::string Character::showStats() {

    // Convert name to std::string
    std::string nameString = name;

    return "Name: " + nameString + "\n"
    "MaxHealth: " + std::to_string(maxHealth) +"\n"
    "Health: " + std::to_string(getHealth()) + "\n"
    "Attack: " + std::to_string(attack) + "\n"
    "Defense: " + std::to_string(defense) + "\n"
    "Speed: " + std::to_string(speed);
}