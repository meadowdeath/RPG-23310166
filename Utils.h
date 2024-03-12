//
// Modified by meadowdeath on 28/02/24.
//
#include<cstdlib>

namespace combat_utils {
    int getRolledAttack(int attack) {
        int lowerLimit = (attack * 80) / 100;
        return (rand() % (attack - lowerLimit + 1)) + lowerLimit;
    }

    int getRolledDefense(int defense) {
        // increase the defense by 20%
        int lowerLimit = (defense * 20) / 100;
        return (rand() % (defense - lowerLimit + 1)) + lowerLimit;
    }
}

namespace double_to_int {
    int double_to_int(double value) {
        return static_cast<int>(value);
    }
}