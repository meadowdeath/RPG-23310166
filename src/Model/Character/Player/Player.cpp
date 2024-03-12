//
// Modified by meadowdeath on 28/02/24.
//

#include "../../../../include/Model/Character/Player/Player.h"

#include <utility>
#include <iostream>

Player::Player(std::string _name, int _maxHealth, int _health, int _attack, int _defense, int _speed) :
Character(std::move(_name), _maxHealth, _health, _attack, _defense, _speed, CharacterState::IDLE) {
    level = 1;
    experience = 0;
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

void Player::levelUp() {
    level++;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }
}

void Player::attacking() {
    changeState(CharacterState::ATTACK);
}

void Player::defending() {
    changeState(CharacterState::DEFEND);
}

void Player::idle() {
    changeState(CharacterState::IDLE);
}