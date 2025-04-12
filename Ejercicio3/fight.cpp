#include "../Ejercicio2/characterFactory.h"

//  1->Golpe Fuerte | 2->Golpe Rápido | 3->Defensa y Golpe

// 0->empate | 1->gana player1 | 2->gana player2
int decideWinner(int player1Move, int player2Move);
void enterToContinue();

int main() {
    // Creación de personajes
    int player2Type = CharacterFactory::randint(0,8);

    unique_ptr<Character> player2 = CharacterFactory::makeCharacter(CharacterFactory::randint(0,8), 100, CharacterFactory::randfloat(0.0,0.5), 1);
    
    cout << "Elegir tipo de personaje" << endl;
    cout << "\t1.Sorcerer\n\t2.Conjurer\n\t3.Wizard\n\t4.Necromancer\n\t5.Barbarian\n\t6.Paladin\n\t7.Knight\n\t8.Mercenary\n\t9.Gladiator\n" << endl;
    cout << "> ";
    int player1Type;
    cin >> player1Type;
    if (cin.fail() || player1Type < 0 || player1Type > 9) {
        cout << "Input inválido" << endl;
        return 1;
    }

    unique_ptr<Character> player1 = CharacterFactory::makeCharacter(player1Type-1, 100, CharacterFactory::randfloat(0.0,0.5), 1);

    cout << "Personajes creados con éxito" << endl;
    enterToContinue();

    while (player1->getHP() > 0 && player2->getHP() > 0) {
        system("clear");


    }
}


int decideWinner(int player1Move, int player2Move) {
    if (player1Move == player2Move) return 0;

    else if (player1Move == 1 && player2Move == 2) return 1;
    else if (player1Move == 2 && player2Move == 3) return 1;
    else if (player1Move == 3 && player2Move == 1) return 1;

    else if (player2Move == 1 && player1Move == 2) return 2;
    else if (player2Move == 2 && player1Move == 3) return 2;
    else return 2;
}

void enterToContinue() {
    cout << "[Enter] para continuar" << endl;
    cin.get();
}