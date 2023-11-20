#include <iostream>

/*
    #define ANIMATIE 1 pt a afisa pe ecran dist[][] in timp ce se
    actualizeaza

    #define ANIMATIE 0 pt a afisa pe ecran doar rezultatul
*/

#define ANIMATIE 1
#define NMAX 100

using namespace std;

bool v[NMAX][NMAX];
int dist[NMAX][NMAX];
int gx[4] = {-1, 0, 0, 1};
int gy[4] = {0, -1, 1, 0};

int N, M;
void Read(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> v[i][j];
        }
    }
}
int stanga, dreapta;
pair<int, int> coada[NMAX * NMAX];

void adaugaDr(int x, int y){
    dreapta++;
    coada[dreapta].first = x;
    coada[dreapta].second = y;
}

void eliminaSt(){
    stanga++;
}

int coadaEmpty(){
    return stanga > dreapta;
}

bool inBound(int x, int y){
    return (x >= 0 && x <= N - 1 && y >= 0 && y <= M - 1);
}


void afisMatrice(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 1){
                cout << "! ";
            }
            else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void DrumMinimInMatrice(){
    stanga = 0;
    dreapta = -1;
    adaugaDr(0, 0);
    dist[0][0] = 1;

    while( !coadaEmpty() ){
        int xn = coada[stanga].first;
        int yn = coada[stanga].second;
        ///(xn, yn) = elementul din stanga al cozii

        for(int i = 0; i < 4; i++){
            int xvec = xn + gx[i];
            int yvec = yn + gy[i];
            ///(xvec, yvec) = un vecin pe care il verific

            if(inBound(xvec, yvec) && v[xvec][yvec] == 0 && dist[xvec][yvec] == 0){
                dist[xvec][yvec] = 1 + dist[xn][yn];
                adaugaDr(xvec, yvec);
            }
        }

        if(ANIMATIE == 1){afisMatrice();}

        eliminaSt();
    }
}

void afiseazaDrumul(int x, int y){
    if(x == 0 && y == 0){
        cout << "(0, 0)\n";
        return;
    }

    int CONTINUA = 1;
    for(int i = 0; i < 4 && CONTINUA; i++){
        int xn = x + gx[i];
        int yn = y + gy[i];

        if(inBound(xn, yn) && dist[xn][yn] == dist[x][y] - 1){
            afiseazaDrumul(xn, yn);
            cout << "(" << x << ", " << y << ")\n";

            CONTINUA = 0;
        }
    }
}

int main()
{
    Read();
    cout << "\n";

    DrumMinimInMatrice();

    cout << "Drumul optim are lungimea = ";
    cout << dist[N - 1][M - 1] - 1;
    cout << "\n";

    cout << "Unul din drumurile optime este:\n";
    afiseazaDrumul(N - 1, M - 1);
    cout << "\n";

}
