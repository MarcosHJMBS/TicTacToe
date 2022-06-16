#include "TicTacToeFunctions.h"

int main() {
    std::cout << "JOGO DA VELHA!!! SELECIONE UMA POSIÇÃO DO TABULEIRO DE 1 A 9 PARA JOGAR!\n";

    std::string board = R"(
     1 | 2 | 3 
    ---+---+---
     4 | 5 | 6 
    ---+---+---
     7 | 8 | 9 

    )";


    turnos(board);
    
    //std::cout << board[6] << board[10] << board[14] << board[38] << board[42] << board[46] << board[70] << board[74] << board[78];

}