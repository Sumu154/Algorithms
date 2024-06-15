/*
3 3
1 2 5
2 3 -10
3 1 1

The graph has negative cycle


    1
   / \
10/   \5
 /     \
2-------3-------4
   -12      4

input
4 4
1 2 10
2 3 -12
1 3 5
3 4 4
1 4

output
The distance from src node:
1 -> 0
2 -> 10
3 -> -2
4 -> 2

Now The path from src to dst
1 2 3 4

*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e5;

const int N = 1e5;
vector<pair<int, int>> adja_list[N];
vector<int> d(N, INF);
int parent[N];
int n, m;

bool BellmanFord(int src)
{
    d[src] = 0;

    for(int i=1 ; i<=n-1 ; i++){
        for(int u=1 ; u<=n ; u++){
            for(auto k: adja_list[u]){
                int v = k.first;
                int w = k.second;
                
                if(d[u]!=INF and d[u]+w<d[v]){
                    d[v] = d[u]+w;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for(int u=1 ; u<=n ; u++){
        for(auto k: adja_list[u]){
            int v = k.first;
            int w = k.second;
            if(d[u]!=INF and d[u]+w<d[v]){
                return true; // Negative cycle found
            }
        }
    }

    return false; // No negative cycle
}

void path_print(int src)
{
    int dst = n;
    vector<int> path;
    while(1){
        path.push_back(dst);
        if(dst==src){
            break;
        }
        dst = parent[dst];
    }
    reverse(path.begin(), path.end());
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v, w});
    }

    int src = 1;
    if(BellmanFord(src))
        cout << "Cycle exist";
    else
    {
        cout << "No cycle\npath from source to dest ";
        path_print(src);
    }

}
