//
// Modified by meadowdeath on 28/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../Character.h"

class Enemy: public Character{
private:
    int experience;
public:
    // Constructor to initialize the enemy.
    Enemy(char _name[40], int maxHealth, int _health, int _attack, int _defense, int _speed, int _experience);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefend();

    int getExperience();

    //Methods to change the enemy's state
    void attacking();
    void defending();
    void idle();
};


#endif //RPG_ENEMY_H
