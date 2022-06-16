#include <iostream>
#include <string>
#include <limits>

int playToIndex(int play) {
    switch(play) {
        case 1 : {return 6;};
        break;
        case 2 : {return 10;};
        break;
        case 3 : {return 14;};
        break;
        case 4 : {return 38;};
        break;
        case 5 : {return 42;};
        break;
        case 6 : {return 46;};
        break;
        case 7 : {return 70;};
        break;
        case 8 : {return 74;};
        break;
        case 9 : {return 78;};
        break;
        default: {return -1;};

    }
}

bool checkWin(std::string& board) {

    if(
        (board[6] == board[10] && board[10] == board[14]) || //Casos horizontais de vitória
        (board[38] == board[42] && board[42] == board[46]) ||
        (board[70] == board[74] && board[74] == board[78]) ||

        (board[6] == board[38] && board[38] == board[70]) || //Casos verticais de vitória
        (board[10] == board[42] && board[42] == board[74]) ||
        (board[14] == board[46] && board[46] == board[78]) ||

        (board[6] == board[42] && board[42] == board[78]) || //Casos diagonais de vitória
        (board[14] == board[42] && board[42] == board[70])
      ) {
          return true;
        } else {
            return false;
        }

}

void turnos(std::string& board) {

    for(int i = 1; i <= 9; i++) {

    std::cout << board;

    static int turn = 1;

    if(turn % 2 != 0) {
        std::cout << "Turno do jogador 1: ";
    } else {
        std::cout << "Turno do jogador 2: ";
    }

    int play;                                               //Pegada da jogada do jogador e checagem se ela é int, se esta entre 1 e 9 e se já foi jogada
    static int numbersPlayed[9] = {};
    while(true) {
        std::cin >> play;
        bool playIsInt = !std::cin.fail();
        bool playIsNew = true;
        bool playIsValid = false; 
        if(playIsInt) {
            playIsValid = (1 <= play && play <= 9);
            if(playIsValid) {
                for(int j = 0; j <= 9; j++) {
                    if(numbersPlayed[j] == play) {
                        playIsNew = false;
                    } else {
                        continue;
                    }
                }
            }
        }

        if(playIsInt && playIsValid && playIsNew) {
            numbersPlayed[turn] = play;
            break;
        } else {
            std::cout << "    Jogada inválida, tente novamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if(turn % 2 != 0) {
        board[playToIndex(play)] = 'X';
    } else {
        board[playToIndex(play)] = 'O';
    }

    if(checkWin(board)) {
        std::cout << board;
        int winner = turn % 2 != 0 ? 1 : 2;
        std::cout << "VITÓRIA DO JOGADOR " << winner << "!!!\n" << "    ^w^ OBRIGADO POR JOGAR ^w^\n";
        break;
    }
    if(turn == 9) {
        std::cout << board;
        std::cout << "DEU VELHA!!!\n" << "    ^w^ OBRIGADO POR JOGAR ^w^\n";
    }

    turn++;
    }
}