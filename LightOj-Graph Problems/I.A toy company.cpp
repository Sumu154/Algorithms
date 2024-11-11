#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

const int N = 104;
int visited[N];
vector<long long> d(N, INF);
vector<pair<int, int>> adja_list[N];
int n, m;

void dijkstra(int src)
{
    d[src] = 0;

    priority_queue<pair<long long, int>> p;
    p.push({0, src});
    while(!p.empty()){
        pair<long long, int> head = p.top();
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
                p.push({-d[v], v});
            }
        }
    }
}


int main()
{
    int t;
    cin >> t;
    for(int k=1 ; k<=t ; k++){
        cin >> n >> m;
        for(int i=0 ; i<m ; i++){
            int u, v, w;
            cin >> u >> v >> w;

            adja_list[u].push_back({v, w});
            adja_list[v].push_back({u, w});
        }

        int src = 1;
        dijkstra(src);

        cout << "Case " << k << ": ";
        if(d[n] != INF){
            cout << d[n] << "\n";
        }
        else{
            cout << "Impossible\n";
        }

        for(int i=0 ; i<N ; i++){
            adja_list[i].clear();
        }
        memset(visited, 0, sizeof(visited));
        fill(d.begin(), d.end(), INF);
    }
}
