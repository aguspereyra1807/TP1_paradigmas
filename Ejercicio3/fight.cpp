#include "../Ejercicio2/characterFactory.h"
#include <iomanip>
#include <limits>

//  1->Golpe Fuerte | 2->Golpe Rápido | 3->Defensa y Golpe

// 0->empate | 1->gana player1 | 2->gana player2
int decideWinner(int player1Move, int player2Move);
void enterToContinue();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Creación de personajes
    vector<int> weapons2 = {CharacterFactory::randint(0,8)};
    unique_ptr<Character> player2 = CharacterFactory::makeCharacter(CharacterFactory::randint(0,8), 100, CharacterFactory::randfloat(0.1,0.5), weapons2);
    
    cout << "Choose your character" << endl;
    cout << "\t- 1.Sorcerer\n\t- 2.Conjurer\n\t- 3.Wizard\n\t- 4.Necromancer\n\t- 5.Barbarian\n\t- 6.Paladin\n\t- 7.Knight\n\t- 8.Mercenary\n\t- 9.Gladiator\n" << endl;
    cout << "> ";
    int player1Type;
    cin >> player1Type;
    if (cin.fail() || player1Type < 0 || player1Type > 9) {
        cout << "Invalid input" << endl;
        return 1;
    }

    vector<int> weapons1;
    cout << "Choose your weapon" << endl;
    cout << "\t- 1.Potion\n\t- 2.Speels Book\n\t- 3.Amulet\n\t- 4.Cane\n\t- 5.Simple Axe\n\t- 6.Double Axe\n\t- 7.Sword\n\t- 8.Spear\n\t- 9.Club\n" << endl;
    cout << "> ";
    int weapon1Type;
    cin >> weapon1Type;
    if (cin.fail() || weapon1Type < 0 || weapon1Type > 9) {
        cout << "Invalid input" << endl;
        return 1;
    }
    weapons1.push_back(weapon1Type);

    unique_ptr<Character> player1 = CharacterFactory::makeCharacter(player1Type-1, 100, CharacterFactory::randfloat(0.1,0.5), weapons1);

    cout << "Players created succesfuly" << endl;
    enterToContinue();

    while (player1->getHP() > 0 && player2->getHP() > 0) {
        system("clear");
        cout << "Choose your next move" << endl;
        cout << "==================================================================\n" 
             << "|| 1. Strong Attack || 2. Quick Attack || 3. Defense and Attack ||\n" 
             << "==================================================================" << endl;
        cout << "> ";
        int move1, move2, winner;
        cin.clear();
        cin >> move1;
        if (cin.fail() || move1 < 1 || move1 > 3) {
            cerr << "Invalid input, try again" << endl;
            enterToContinue();
            cin.clear();
            continue;
        }
        
        move2 = CharacterFactory::randint(1,3);

        winner = decideWinner(move1, move2);

        switch(winner) {
            case 0: {
                string moveStr;
                if (move1 == 1) moveStr = "Strong Attack";
                else if (move1 == 2) moveStr = "Quick Attack";
                else moveStr = "Defense and Attack";
    
                cout << "Both chosed '" << moveStr << "', is a tie." << endl;
                enterToContinue();
                break;
            }
            case 1: {
                pair<string, double> play = player1->doDamage(player2->getResistance());
                player2->receiveDamage(play.second);
                cout << std::fixed << std::setprecision(2);
                cout << "Player1 attacks with a/an " << play.first << " and makes " << play.second << " damage to Player2" << endl;
                enterToContinue();
                break;
            }
            case 2: {
                pair<string, double> play = player2->doDamage(player1->getResistance());
                player1->receiveDamage(play.second);
                cout << std::fixed << std::setprecision(2);
                cout << "Player2 attacks with a/an " << play.first << " and makes " << play.second << " damage to Player1" << endl;
                enterToContinue();
                break;
            }
        }
        cout << " - Player1 HP = " << std::fixed << std::setprecision(2) << player1->getHP() << endl;
        cout << " - Player2 HP = " << std::fixed << std::setprecision(2) << player2->getHP() << endl;
        enterToContinue();
    }

    if (player2->getHP() <= 0) {
        cout << "Player1 wins!" << endl;
        enterToContinue();
        return 0;
    }
    else if (player1->getHP() <= 0) {
        cout << "Player2 wins!" << endl;
        enterToContinue();
        return 0;
    }
}


int decideWinner(int player1Move, int player2Move) {

    if (player1Move == 1 && player2Move == 2) return 1;
    else if (player1Move == 2 && player2Move == 3) return 1;
    else if (player1Move == 3 && player2Move == 1) return 1;
    else if (player2Move == 1 && player1Move == 2) return 2;
    else if (player2Move == 2 && player1Move == 3) return 2;
    else if (player2Move == 3 && player1Move == 1) return 2;

    else return 0;
}

void enterToContinue() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "[Enter] to continue" << endl;
    cin.get();
}