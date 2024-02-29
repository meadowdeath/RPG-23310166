//
// Modified by meadowdeath on 28/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>
#include <utility>

enum class CharacterState  {
    IDLE, // IDLE is the state when the character is not doing anything
    ATTACK,
    DEFEND
};

class Character {
protected:
    std::string name;
    int health;
    int attack;
    int defense;
    int speed;
    CharacterState currentState; // This is the state of the character

public:
    // Constructor to initialize the character's attributes.
    Character(std::string _name, int _health, int _attack, int _defense, int _speed, CharacterState _currentState);

    // Methods that will be implemented in the derived classes.
    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    // Method to change the state of the character.
    void changeState(CharacterState newState) {
        currentState = newState;
    }

    // Method to get the state of the character.
    CharacterState getState() {
        return currentState;
    }

    // Getters for the character's attributes.
    std::string getName();
    int getHealth();
    int getAttack();
    int getDefense();
    int getSpeed();

    // Method to represent the character as a string.
    std::string toString();
};


#endif //RPG_CHARACTER_H
