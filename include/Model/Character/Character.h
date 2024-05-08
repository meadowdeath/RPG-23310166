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
    // TODO: Implement the DEAD state...
};

class Character {
protected:
    char name[40];
    int maxHealth;
    int health;
    int attack;
    int defense;
    int speed;
    int level;

public:
    CharacterState currentState; // This is the state of the character

    // Constructor to initialize the character's attributes.
    Character(char _name[40], int _maxHealth, int _health, int _attack, int _defense, int _speed, int _level, CharacterState _currentState);

    // Methods that will be implemented in the derived classes.
    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    // Method to change the state of the character.
    void changeState(CharacterState newState);

    // Method to get the state of the character.
    CharacterState getState();

    // Getters for the character's attributes.
    std::string getName();
    int getHealth();
    int getMaxHealth();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getLevel();

    // Setters for the character's attributes.

    void restoreHealth();

    // Method to represent the character as a string.
    std::string showStats();
};


#endif //RPG_CHARACTER_H
