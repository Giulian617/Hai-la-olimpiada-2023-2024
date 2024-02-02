#include<bits/stdc++.h>
using namespace std;
int n,target;
long long ans;
vector<int>v;
vector<long long> get_subset_sums(int start,int finish) /// get all subset sums in the interval [start,finish]
{
    int length=finish-start+1;
    vector<long long>ans;
    for(int i=0;i<(1<<length);i++)
    {
        long long sum=0;
        for(int j=0;j<length;j++)
            if(i&(1<<j))
                sum+=v[start+j];
        ans.push_back(sum);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>target;
    v.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];

    vector<long long>left=get_subset_sums(1,n/2);
    vector<long long>right=get_subset_sums(n/2+1,n);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    for(long long value:left)
    {
        int start_idx=lower_bound(right.begin(),right.end(),target-value)-right.begin();
        int end_idx=upper_bound(right.begin(),right.end(),target-value)-right.begin();
        ans+=end_idx-start_idx;
    }
    cout<<ans;
    return 0;
}
