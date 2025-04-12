#include "characterFactory.h"

//  1->Golpe Fuerte | 2->Golpe Rápido | 3->Defensa y Golpe

// 0->empate | 1->gana player1 | 2->gana player2
int decideWinner(int player1Move, int player2Move);

int main() {
    int player2Type = CharacterFactory::randint(0,8);
    unique_ptr<Character> player2 = CharacterFactory::makeCharacter(CharacterFactory::randint(0,8), 100, CharacterFactory::randfloat(0.0,0.5));

}

int decideWinner(int player1Move, int player2Move) {
    if (player1Move == player2Move) return 0;

    else if (player1Move == 1 && player2Move == 2) return 1;
    else if (player1Move == 2 && player2Move == 3) return 1;
    else if (player1Move == 3 && player2Move == 1) return 1;

    else if (player2Move == 1 && player1Move == 2) return 2;
    else if (player2Move == 2 && player1Move == 3) return 2;
    else if (player2Move == 3 && player1Move == 1) return 2;
}

