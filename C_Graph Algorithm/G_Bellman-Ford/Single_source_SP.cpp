/*
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

output
YES

*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e5;

const int N = 100;
vector<int> d(N, INF);
vector<pair<int, int>> adja_list[N];
int n, m;

bool BellmanFord(int src) 
{
    d[src] = 0;

    for(int i=1 ; i<=n-1 ; i++){          //n-1 ta iteration
        for(int u=1 ; u<=n ; u++){        //each iteration e 1..n porjonto distance update korbo
            for(auto k: adja_list[u]){
                int v = k.first;
                int w = k.second;

                if(d[u]!=INF and d[u]+w<d[v]){
                    d[v] = d[u]+w;
                }
            }
        }
    }

    // Check for negative cycles
    for(int u=1 ; u<=n ; u++){   //nth iteration 
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


int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int  u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
        //adja_list[v].push_back({u,w});
    }

    int src = 1;
    if(BellmanFord(src))
        cout << "cycle exist";
    else{
        for(int i=1 ; i<=n ; i++){
            cout << d[i] << " ";
        }
    }
}


