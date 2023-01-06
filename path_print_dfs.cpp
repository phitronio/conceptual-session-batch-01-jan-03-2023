#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
vector<int> level;
vector<bool> visited;
vector<int> parent;
vector<int> print_path(int d)
{
    vector<int> path;
    int x=d;
    while(x!=-1)
    {
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
    return path;
}
void dfs(int p)
{
    for(int i=0;i<adj[p].size();i++)
    {
        int child=adj[p][i];
        if(level[p]+1 <= level[child])
        {
            level[child] = level[p]+1;
            parent[child]=p;
        }
        if(!visited[child])
        {
            visited[child]=true;
            dfs(child);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    level.resize(n,INT_MAX);
    visited.resize(n,false);
    parent.resize(n,-1);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int src,dest;
    cin>>src>>dest;
    level[src]=0;
    dfs(src);
    vector<int> path = print_path(dest);
    for(int x: path)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
//7 8
//0 5
//1 0
//1 2
//0 2
//2 3
//3 4
//5 6
//6 4

