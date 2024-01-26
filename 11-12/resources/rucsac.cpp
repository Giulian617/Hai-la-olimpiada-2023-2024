#include<bits/stdc++.h>
using namespace std;
const int NMAX=1005;
int n,G;
double ans;
struct object
{
    int cost,weight;
    friend bool operator <(object A,object B)
    {
        if(A.cost*B.weight>B.cost*A.weight)
            return 1;
        return 0;
    }
}v[NMAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>G;
    for(int i=1;i<=n;i++)
        cin>>v[i].weight>>v[i].cost;
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
        if(G>=v[i].weight)
        {
            ans+=v[i].cost;
            G-=v[i].weight;
        }
        else
        {
            ans+=1.0*G*v[i].cost/v[i].weight;
            i=n+1;
        }
    cout<<ans;
    return 0;
}
