//
// Modified by meadowdeath on 28/02/24.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H
#include "../Character.h"
#include "../../Files/FileHandler.h"


class Player: public Character {
    //TODO: Implement Classes (Mage, Warrior, Rogue, etc..)
    //TODO: Implement Inventory
private:

    int currentXP;
    int leftOverXP;
    int nextLevelXP;

public:
    // Constructor to initialize the player
    Player();

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void doDefend();

    //void gainExperience(int exp);
    //TODO: Implement use object

    // Getters
    int getCurrentXP();
    int getLeftOverXP();
    int getNextLevelXP();

    // Setters
    void setMaxHealth();
    void setAttack();
    void setDefense();
    void setSpeed();
    void setLevel();
    void setCurrentXP(int _currentXP);
    void setLeftOverXP(int _leftOverXP);
    void setNextLevelXP();

    void improvePlayerStats(int chosenStat);

    // Methods to change the player's state
    void attacking();
    void defending();
    void idle();

    // Serialize the player's attributes
    void serialize(const char* filename);

    // Unserialize the player's attributes
    void unserialize(const char* filename);


};


#endif //RPG_PLAYER_H
