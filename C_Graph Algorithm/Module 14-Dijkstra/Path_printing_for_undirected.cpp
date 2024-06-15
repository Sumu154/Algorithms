/*
source to destination path print korbe
  1     5
  |\4 3/ \2
  | \ / 6 \
 4|  3-----4
  | / \   /
  |/2 1\ /3
  2     6

6 8

1 2 4
1 3 4
2 3 2
3 5 3
3 6 1
3 4 6
5 4 2
6 4 3

source = 1

output -> 1 3 6


time comp -> O(E*logV)

n= 1e5, m= 1e5
max_weight = 1e6
int worst case, dist can be 1e5*1e6 = 1e11

pairer 1st element -> distance
pairer 2nd element -> node

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll  INF = 1e18;

const int N = 1e5+5;
int visited[N];
vector<ll> parent(N, -1);
vector<ll> d(N, INF);
vector<pair<int, int>> adja_list[N];
int n, m;

void dijkstra(int src)
{
    d[src] = 0;
    priority_queue<pair<ll, int>> p;
    p.push({0, src});

    while(!p.empty()){
        pair<ll, int> head = p.top();
        p.pop();
        int u = head.second;
        if(visited[u]){
            continue;
        }

        visited[u] = 1;
        for(auto i: adja_list[u]){
            int v = i.first;
            int w = i.second;

            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                parent[v] = u;
                p.push({-d[v], v});
            }
        }
    }
}

void print_path()
{
    vector<int> path;
    while(n != -1){
        path.push_back(n);
        n = parent[n];
    }

    reverse(path.begin(), path.end());
    for(int i: path){
        cout << i << " ";
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
        //adja_list[v].push_back({u,w});
    }

    int src = 1;
    dijkstra(src);

    if(visited[n]){
        print_path();
    }
    else{
        cout << "IMPOSSIBLE";
    }

}

