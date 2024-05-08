//
// Modified by meadowdeath on 28/02/24.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H
#include "../Character.h"

class Player: public Character {
    //TODO: Implement Classes (Mage, Warrior, Rogue, etc..)
    //TODO: Implement Inventory
private:

    int currentXP;
    int leftOverXP;
    int nextLevelXP;

    void levelUp();

public:
    // Constructor to initialize the player
    Player(char _name[40], int _maxHealth, int _health, int _attack, int _defense, int _speed, int _level, int _currentXP, int _leftOverXP, int _nextLevelXP);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefend();

    void gainExperience(int exp);
    //TODO: Implement use object

    // Getters
    int getCurrentXP();
    int getLeftOverXP();
    int getNextLevelXP();

    // Setters


    // Methods to change the player's state
    void attacking();
    void defending();
    void idle();
};


#endif //RPG_PLAYER_H
