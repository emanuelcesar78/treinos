#include <iostream>
#include <conio.h>

using namespace std;

const int largura = 10;
const int altura = 10;

int moeda = 0;
char map[altura][largura] = {
    {'*','*','*','*','*','*','*','*','*','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ','O','*'},
    {'*','*','*','*','*','*','*','*',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ','*',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ','V',' ',' ',' ','*',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ','*','*','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
};

void visualizar_mapa () {

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            cout<<map[i][j];
        }
        cout<<endl;
    }

}


class NPC {

public:

    int npc_x = 0,npc_y = 0, alvo_x = 0, alvo_y = 0;

    void movimento(char tecla) {

        for (int i = 0; i<altura; i++) {
            for (int j = 0; j<largura; j++) {

                if (map[i][j]=='O') {

                    npc_y = i;
                    npc_x = j;
                }

                if (map[i][j]=='V') {

                    alvo_y = i;
                    alvo_x = j;
                }
            }
        }

        map[npc_y][npc_x] = 'O';

        int X = alvo_x - npc_x;
        int Y = alvo_y - npc_y;

        int novo_x = npc_x;
        int novo_y = npc_y;


        if (abs(X) > abs(Y))  {

            int tentaiva_x = npc_x + ((X > 0) ? 1: (X < 0 ? - 1:0));

            if (map[npc_y][tentaiva_x] != '*' && map[npc_y][tentaiva_x] != 'O') {

                novo_x = tentaiva_x;
            }
            else {
                int tentativa_y = npc_y + ((Y > 0) ? 1: (Y < 0 ? -1: 0));

                if (map[tentativa_y][npc_x] != '*' && map[tentativa_y][npc_x] != 'O') {
                    novo_y = tentativa_y;
                }
            }

        }

        else {

            int tentativa_Y = npc_y + ((Y > 0) ? 1: (Y < 0 ? -1: 0));

            if (map[tentativa_Y][npc_x] != '*' &&  map[tentativa_Y][npc_x] != 'O') {

                novo_y = tentativa_Y;
            }
            else {
                int tentativa_X = npc_x + ((X > 0) ? 1: (X < 0 ? -1: 0));

                if (map[npc_y][tentativa_X] != '*' && map[npc_y][tentativa_X] != 'O') {

                    novo_x = tentativa_X;
                }
            }

        }


        if ((novo_x != npc_x || novo_y != npc_y) && (map[novo_y][novo_x] == ' ' || map[novo_y][novo_x] == 'V')) {

            map[npc_y][npc_x] = ' ';
            map[novo_y][novo_x] = 'O';
        }

    }


};


int main() {
    while (true) {

        system("cls");

        visualizar_mapa();


        int alvo_x = 0, alvo_y = 0 , npc_x = 0, npc_y =0;

        for (int i = 0; i< largura; i++) {

            for (int j = 0; j<largura; j++) {

                if (map[i][j]=='O') {

                    npc_x = i;
                    npc_y = j;
                }

                if (map[i][j] == 'V') {
                    alvo_x = i;
                    alvo_y = j;
                }
            }
        }

        if (map[npc_y][npc_x] == map[alvo_y][alvo_x]) {

            cout<<"Vitoria do jogador"<<endl;
            break;
        }

        char l = _getch();

        NPC inimigo;

        inimigo.movimento(l);
    }

    return 0;
}
