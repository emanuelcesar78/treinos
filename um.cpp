#include <iostream>
#include <conio.h>

using namespace std;

const int largura = 10;
const int altura = 10;

char map [largura][altura] ={
    {'*','*','*','*','*','*','*','*','*','*'},
    {'*','o',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ','o',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ','^',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ','o',' ','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
    } ;

int jogador_x = 4;
int jogador_y = 5;

int Moeda = 0;

void visualizar_mapa() {

    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            cout<<map[i][j];
        }
        cout<<endl;
    }
}

void movimento_jogador(char tecla) {

    int movimento_x = jogador_x;
    int movimento_y = jogador_y;

    if (tecla == 'a' || tecla=='A') {movimento_x --;}
    if (tecla == 'd' || tecla=='D') {movimento_x ++;}
    if (tecla == 'w' || tecla=='W') {movimento_y --;}
    if (tecla == 's' || tecla=='S') {movimento_y ++;}

    if (map[movimento_y][movimento_x] == ' '|| map[movimento_y][movimento_x] == 'o') {

        if (map[movimento_y][movimento_x] == 'o') {Moeda++;}

        map[jogador_y][jogador_x] = ' ';

        jogador_x = movimento_x;
        jogador_y = movimento_y;

        map[jogador_y][jogador_x] = '^';

    }
}

int main() {

    while (true) {
        system("cls");

        cout<<"Moedas coletadas: "<<Moeda<<endl;

        visualizar_mapa();
        char te= _getch();

        movimento_jogador(te);
    }


}
