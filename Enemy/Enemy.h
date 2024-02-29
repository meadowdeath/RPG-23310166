//
// Modified by meadowdeath on 28/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../Character/Character.h"

class Enemy: public Character{
private:
    int experience;
public:
    // Constructor to initialize the enemy.
    Enemy(std::string _name, int _health, int _attack, int _defense, int _speed, int _experience);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    int getExperience();

    //Methods to change the enemy's state
    void attacking();
    void defending();
};


#endif //RPG_ENEMY_H
