/*
    Algoritmul fill; El se foloseste de recursivitate (care
    functioneaza printr-o stiva in interior de fapt)
    si gaseste un drum in matrice (dar nu optim de obicei).

    Algoritmul merge cat de mult se poate intr-o anumita directie,
    dupa care alege alta si continua.
    El are un bias in functie de ordinea in care decidem sa verificam vecinii.

    Exemplu de input pt care drumul gasit este foarte prost:
4 5
0 0 0 0 0
0 1 0 1 0
0 0 0 0 0
0 0 0 1 0

    Schimbati
    #define ANIMATIE 0
    in
    #define ANIMATIE 1
    pentru a vedea exact drumul, pas cu pas


*/
#include <iostream>

#define ANIMATIE 1
#define NMAX 100

using namespace std;

bool viz[NMAX][NMAX];
bool v[NMAX][NMAX];
int gx[4] = {-1, 0, 0, 1};
int gy[4] = {0, -1, 1, 0};
///bias: sus, stanga, dreapta, jos

int N, M;
void Read(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> v[i][j];
        }
    }
}

void afiseaza(){
    ///imi afiseaza vectorul de vizitati
    ///mai putin pt obstacole; acolo afiseaza "!"
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 1){
                cout << "! ";
            }
            else {
                cout << viz[i][j] << ' ';
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

bool inBound(int x, int y){
    return (x >= 0 && x <= N - 1 && y >= 0 && y <= M - 1);
}

void filll(int x, int y){
    viz[x][y] = 1;

    if(ANIMATIE){
        cout << "A intrat in casuta (" << x << ", " << y << ")\n";
        afiseaza();

        if(x == N - 1 && y == M - 1){
            cout << "Am ajuns la final!\n";
            return;
            ///Pana si functiile void pot da return!
            ///este ca un break
        }

        cout << "\n";
    }


    for(int i = 0; i < 4; i++){
        int xv = x + gx[i];
        int yv = y + gy[i];
        ///vecin cu coordonatele (xv, yv)

        if(inBound(xv, yv) && v[xv][yv] == 0 && !viz[xv][yv]){
            filll(xv, yv);
        }
    }

}

int main()
{
    Read();
    filll(0, 0);

}
