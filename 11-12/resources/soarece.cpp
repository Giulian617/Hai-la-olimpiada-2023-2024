#include <bits/stdc++.h>
using namespace std;
ifstream f("soarece.in");
ofstream g("soarece.out");
int n,m,is,js,ib,jb,cnt,a[15][15];
int di[4]= {-1,0,1,0};
int dj[4]= {0,1,0,-1};
bool verif(int i,int j)
{
    return i>=1 && i<=n && j>=1 && j<=m;
}
void bkt(int is,int js,int pas)
{
    for(int d=0; d<4; d++)
    {
        int in=is+di[d],jn=js+dj[d];
        if(verif(in,jn) && a[in][jn]==0)
        {
            a[in][jn]=pas;
            if(in==ib && jn==jb)
                cnt++;
            else bkt(in,jn,pas+1);
            a[in][jn]=0;
        }
    }
}
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            f>>a[i][j];
            a[i][j]*=-1;
        }
    }
    f>>is>>js>>ib>>jb;
    a[is][js]=1;
    bkt(is,js,2);
    g<<cnt;
    return 0;
}
