#include <iostream>

using namespace std;

void bordare(int N, int M){
    for(int j = 0; j <= M + 1; j++){
        ///bordeaza cu 1 sus si jos
        v[0][j] = 1;
        v[N + 1][j] = 1;
    }
    for(int i = 0; i <= N + 1; i++){
        ///bordeaza cu 1 in stanga si dreapta matricei
        v[i][0] = 1;
        v[i][M + 1] = 1;
    }
}

int main()
{

}
