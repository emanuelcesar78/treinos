#include <iostream>
#include <conio.h>

using namespace std;

const int largura = 10;
const int altura = 10;

char map [largura][altura] ={
    {'*','*','*','*','*','*','*','*','*','*'},
    {'*','o',' ',' ',' ',' ',' ',' ','O','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ','^',' ',' ',' ','o','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ','o','V','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
    };

int movimento_jogador_x = 4;
int movimento_jogador_y = 5;

int vida_jogador = 3;

int Moeda = 0;

void mostra_mapa() {

    //essa parte do codigo serve para imprimir o mapa do jogo

    for (int i = 0; i < largura; i++) {
        for (int f = 0; f<altura; f++) {

            cout << map[i][f];
        }

        cout<<endl;
    }

    // aplica-se uma matriz que conta todos os itens da arrys, logo a imprime mostrando o conteudo.
}

void movimento_jogador(char tecla) {
    // movimento responsavel pelo jogador.

    int jogador_x = movimento_jogador_x;
    int jogador_y = movimento_jogador_y;

    //cada tecla que for pressionada fara o jogador se movimentar de um lado a outro.

    if (tecla == 'a' || tecla == 'A'){jogador_x--;}
    if (tecla == 'd' || tecla == 'D'){jogador_x++;}
    if (tecla == 's' || tecla == 'S'){jogador_y--;}
    if (tecla == 'w' || tecla == 'W'){jogador_y++;}

    if (map[jogador_y][jogador_x] == ' '|| map[jogador_y][jogador_x] == 'o'){

        // garante que o codigo localize onde esta o jogador e caso mova ele limpa o local que saiu.

        if (map[jogador_y][jogador_x] == 'o') {Moeda++;}//as moedas são representadas por 'o', caso elaas sejam pegas aumentam o numero de contas.


        map[movimento_jogador_y][movimento_jogador_x] = ' ';

        movimento_jogador_x = jogador_x;
        movimento_jogador_y = jogador_y;

        map[movimento_jogador_y][movimento_jogador_x] = '^';

    }

}



class NPC {

public:

    int vitorias = 0;

    int derrotas = 0;

    static void movimento_NPC() {

        int npc_x = 0,npc_y =0 , alvo_x = 0 ,alvo_y = 0;

        for (int i = 0; i<largura; i++) {

            for (int f = 0; f<altura; f++) {

                if (map [i][f] == 'O') {
                    npc_x = f;
                    npc_y = i;
                }

                if (map [i][f] == 'V') {
                    alvo_x = f;
                    alvo_y = i;
                }
            }
        }

        map [npc_y][npc_x] = ' ';

        int dx = alvo_x - npc_x;
        int dy = alvo_y - npc_y;

        if (abs(dx) > abs(dy)) {
            npc_x += (dx>0) ? 1:-1;
        }
        if (abs(dy) > abs(dx)) {
            npc_y += (dy > 0) ? 1:-1;
        }

        if (map[npc_y][npc_x] == ' '|| map[npc_y][npc_x] == 'V') {

            map[npc_y][npc_x] = 'O';
        }
    }

};

int main () {

    while (true) {

        system("cls");
        mostra_mapa();

        char tecla = _getch();

        movimento_jogador(tecla);

        NPC::movimento_NPC();

    }
}
