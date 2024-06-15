/*
https://docs.google.com/document/d/1rMQqq63aZ4zevRmPhfQkLmeEB3Ti8gtPLTmZjp0msz4/edit
directed
6 8
1 2 10
1 3 15
2 4 12
2 6 15
3 5 10
4 6 1
4 5 2
6 5 5

0 10 15 22 24 23
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const long long INF = 1e18;

const int N = 1e5+5;
bool visited[N];
vector<ll> d(N, INF);
vector<pair<int, int>> adja_list[N];
int n, m;

void dijkstra(int src)
{
    priority_queue<pair<ll, int>> p;
    p.push({0, src});
    d[src] = 0;

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

            if(d[u]+w < d[v]){  //w = cost of u-->v
                d[v] = d[u]+w;
                p.push({-d[v], v});
            }
        }
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

    for(int i=1 ; i<=n ; i++){
        cout << d[i] << " ";
    }
}


