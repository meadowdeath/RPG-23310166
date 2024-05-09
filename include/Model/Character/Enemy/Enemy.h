//
// Modified by meadowdeath on 28/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../Character.h"

class Enemy: public Character{
private:
    int givenXP;
public:
    // Constructor to initialize the enemy.
    Enemy(char _name[40], int maxHealth, int _health, int _attack, int _defense, int _speed, int _level, int _givenXP);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefend();

    // Getters
    int getGivenXP();

    // Setters
    void setMaxHealth();
    void setAttack();
    void setDefense();
    void setSpeed();
    void setLevel();
    void setGivenXP();

    void improveEnemyStats();

    //Methods to change the enemy's state
    void attacking();
    void defending();
    void idle();
};


#endif //RPG_ENEMY_H
