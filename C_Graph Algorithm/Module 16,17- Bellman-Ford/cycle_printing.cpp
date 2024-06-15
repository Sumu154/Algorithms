/*

4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output
YES
1 2 4 1

*/

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e7;

const int N = 1e5+5;
vector<int> d(N, INF);
int parent[N];
vector<pair<int, int>> adja_list[N];
int n, m, selected;

void cycle_print()
{
    for(int i=1 ; i<=n-1 ; i++){
        selected = parent[selected];
    }

    vector<int> path;
    int first = selected;
    path.push_back(selected);
    while(true){
        selected = parent[selected];
        path.push_back(selected);
        if(selected == first)
           break;
    }

    reverse(path.begin(), path.end());
    for(auto i: path){
        cout << i << " ";
    }
}

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

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
    }

    int src = 1;
    bool found = BellmanFord(src);

    if(found){
        cout << "YES\n";
        cycle_print();
    }
    else
        cout << "NO\n";

}

