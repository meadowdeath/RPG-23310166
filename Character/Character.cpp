//
// Modified by meadowdeath on 28/02/24.
//

#include "Character.h"

#include <utility>
Character::Character(std::string _name, int _health, int _attack, int _defense, int _speed, CharacterState _currentState) {
    name = std::move(_name);
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    currentState = _currentState;

}

std::string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
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

std::string Character::toString() {
    return "Name: " + name + "\nHealth: " + std::to_string(health) + "\nAttack: " + std::to_string(attack) + "\nDefense: " + std::to_string(defense) + "\nSpeed: " + std::to_string(speed);
}