    #include<bits/stdc++.h>
using namespace std;
vector<int>parent;
int find_parent(int x)
{
    if(parent[x] == -1) return x;
    return find_parent(parent[x]);
}
void union_operation(int u,int v)
{
    int parentU = find_parent(u);
    int parentV = find_parent(v);
    parent[parentU] = parentV;
}
int main()
{
    int n,e;
    cin>>n>>e;
    bool cyclic=false;
    parent.resize(n,-1);
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        int parentU = find_parent(u);
        int parentV = find_parent(v);
        if(parentU == parentV)
        {
            cyclic = true;
        }
        else
        {
            union_operation(u,v);
        }
    }
    if(cyclic) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
