#include <string>

using namespace std;

class Weapon {
    public:
        virtual string getName() = 0;
        virtual double getDamage() = 0;


    protected:
        string name;
        double damage;

};