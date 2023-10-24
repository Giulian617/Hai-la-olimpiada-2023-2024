#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("fill.in");
ofstream fout ("fill.out");

bool v[100][100];
bool vizitata[100][100];
int stCol[100 * 100];
int stLin[100 * 100];
int nr_elem = 0;
int N, M;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void adauga(int lin, int col){
    stLin[nr_elem] = lin;
    stCol[nr_elem] = col;

    nr_elem++;
}

void elimina(){
    nr_elem--;
}

int varf_lin(){
    return stLin[nr_elem - 1];
}
int varf_col(){
    return stCol[nr_elem - 1];
}
bool goala(){
    if(nr_elem == 0){
        return 1;
    }
    else {
        return 0;
    }
}
bool ieseDinMatrice(int lin, int col){
    if(0 <= lin && lin <= N - 1 && 0 <= col && col <= M - 1){
        return 0; ///nu iese din matrice
    }
    else {
        return 1; ///iese din matrice
    }
}

int main()
{
    fin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            fin >> v[i][j];
            ///1 = uscat
            ///0 = apa
        }
    }


    int nr_insule = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 1 && vizitata[i][j] == 0){
                nr_insule++;

                adauga(i, j); ///adaug in stiva( (i, j) );
                while(goala() == 0){ ///stiva nu e goala
                    int x = varf_lin(); ///linia
                    int y = varf_col(); ///coloana
                    ///(x, y) = elementul din vf stivei

                    vizitata[x][y] = 1;


                    elimina();
                    ///elimin din stiva varful;

                    ///luam toti vecinii:
                    int xn;
                    int yn;
                    for(int k = 0; k < 4; k++){
                        xn = x + di[k];
                        yn = y + dj[k];

                        if((ieseDinMatrice(xn, yn) == 0) && v[xn][yn] == 1 && vizitata[xn][yn] == 0){
                            adauga(xn, yn);
                        }
                    }
                }
            }
        }
    }

    fout << nr_insule << "\n";
    return 0;
}
