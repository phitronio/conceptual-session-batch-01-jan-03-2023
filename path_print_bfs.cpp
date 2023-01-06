#include<bits/stdc++.h>
using namespace std;
vector<int> v[10000];
vector<bool> visited;
vector<int> dist;
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
vector<int> bfs(int src,int d)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;
    parent[src]=-1;
    visited[src]=true;
    while(!q.empty())
    {
        int p = q.front();
//        cout<<p<<endl;
        q.pop();
        if(p==d)
        {
            vector<int> path=print_path(d);
            return path;
        }
        for(int i=0;i<v[p].size();i++)
        {
            int child=v[p][i];
            if(!visited[child])
            {
                parent[child]=p;
                visited[child]=true;
                dist[child]=dist[p]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    visited.resize(n,false);
    dist.resize(n,0);
    parent.resize(n,-1);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,dest;
    cin>>src>>dest;
    vector<int> path=bfs(src,dest);
    for(int val:path) cout<<val<<" ";
    cout<<endl;
    return 0;
}
//4 4
//0 1
//0 2
//1 2
//1 3
