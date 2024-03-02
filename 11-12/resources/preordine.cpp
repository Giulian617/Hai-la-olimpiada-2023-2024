#include <bits/stdc++.h>
using namespace std;
ifstream f("preordine.in");
ofstream g("preordine.out");
struct
{
    int st,dr,val;
} v[1005];
void preordine(int nod)
{
    if(nod)
    {
        g<<v[nod].val<<" ";
        preordine(v[nod].st);
        preordine(v[nod].dr);
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
    preordine(rad);
    return 0;
}
