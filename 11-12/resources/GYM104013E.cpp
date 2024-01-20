#include<bits/stdc++.h>
using namespace std;
const int NMAX=200005;
int n,value;
struct edge
{
    int a,b,w;
} edges[NMAX];
vector<int>ans,bad,eulerian_path,graph[NMAX];
void normalization()
{
    vector<int>v;
    map<int,int>normalize;
    for(int i=1; i<=n; i++)
    {
        v.push_back(edges[i].a);
        v.push_back(edges[i].b);
    }
    sort(v.begin(),v.end());
    for(int i=0,cnt=1; i<(int)v.size(); i++)
        if(normalize.find(v[i])==normalize.end())
        {
            normalize[v[i]]=cnt;
            cnt++;
        }
    for(int i=1; i<=n; i++)
    {
        edges[i].a=normalize[edges[i].a];
        edges[i].b=normalize[edges[i].b];
    }
    value=normalize[value];
}
void create_graph()
{
    for(int i=1; i<=n; i++)
        if(edges[i].w)
            graph[edges[i].a].push_back(i);
}
void dfs_euler(int node)
{
    while(!graph[node].empty())
    {
        int edge_idx=graph[node].back();
        graph[node].pop_back();
        dfs_euler(edges[edge_idx].b);
        eulerian_path.push_back(edge_idx);
    }
}
bool check_eulerian()
{
    int curr_node=value;
    for(int edge:eulerian_path)
        if(edges[edge].a!=curr_node)
            return 0;
        else
            curr_node=edges[edge].b;
    for(int i=1;i<NMAX;i++)
        if(!graph[i].empty())
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>value;
    for(int i=1; i<=n; i++)
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    normalization();
    create_graph();
    dfs_euler(value);
    reverse(eulerian_path.begin(),eulerian_path.end());
    if(check_eulerian())
    {
        /// add bad edges that don't start from value to the solution
        for(int i=1; i<=n; i++)
            if(!edges[i].w && value!=edges[i].a)
                ans.push_back(i);
            else if(!edges[i].w)
                bad.push_back(i);

        int curr_node=value;
        bool first_time=1;
        for(int edge:eulerian_path)
        {
            ans.push_back(edge);
            curr_node=edges[edge].b;
            if(curr_node!=value && first_time)
            {
                for(int bad_edge:bad)
                    ans.push_back(bad_edge);
                first_time=0;
            }
        }

        if(ans.size()==n)
        {
            cout<<"Yes"<<'\n';
            for(int edge:ans)
                cout<<edge<<' ';
        }
        else
            cout<<"No";
    }
    else
        cout<<"No";
    return 0;
}