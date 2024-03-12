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
    int level;
    int experience;

    void levelUp();

public:
    // Constructor to initialize the player
    Player(std::string _name, int _maxHealth, int _health, int _attack, int _defense, int _speed);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefend();

    void gainExperience(int exp);
    //TODO: Implement use object

    // Methods to change the player's state
    void attacking();
    void defending();
    void idle();
};


#endif //RPG_PLAYER_H
