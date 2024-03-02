#include <bits/stdc++.h>
using namespace std;
ifstream f("postordine.in");
ofstream g("postordine.out");
struct
{
    int st,dr,val;
}v[1005];
void postordine(int nod)
{
    if(nod)
    {
        postordine(v[nod].st);
        postordine(v[nod].dr);
        g<<v[nod].val<<" ";
    }
}
int n,rad,t[1005];
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>v[i].val>>v[i].st>>v[i].dr;
        t[v[i].st]=t[v[i].dr]=i;
    }
    for(int i=1;i<=n;i++)
        if(t[i]==0)
    {
        rad=i;
        break;
    }
    postordine(rad);
    return 0;
}
