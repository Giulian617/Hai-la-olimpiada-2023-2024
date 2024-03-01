#include <bits/stdc++.h>
using namespace std;
ifstream f("inordine.in");
ofstream g("inordine.out");
struct
{
    int st,dr,val;
} v[1005];
void inordine(int nod)
{
    if(nod)
    {
        inordine(v[nod].st);
        g<<v[nod].val<<" ";
        inordine(v[nod].dr);
    }
}
int n,t[1005],rad;
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>v[i].val>>v[i].st>>v[i].dr;
        t[v[i].st]=t[v[i].dr]=i;
    }
    for(int i=1; i<=n; i++)
        if(t[i]==0)
        {
            rad=i;
            break;
        }
    inordine(rad);
    return 0;
}
