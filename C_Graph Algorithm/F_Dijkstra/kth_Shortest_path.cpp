#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

const int N = 2e5+5;
//visited lagbe na ei problem e
vector<vector<ll>> d;
vector<vector<pair<int, ll>>> adja_list;
int n, m, k;

void dijkstra(int src)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0,src});

    while(!pq.empty()){
        int u = pq.top().second;
        int dst = pq.top().first;
        pq.pop();

        if(d[u][k-1] < dst){
            continue;
        }

        for(auto i: adja_list[u]){
            int v = i.first;
            ll w = i.second;

            if(dst+w < d[v][k-1] ){
                d[v][k-1] = dst+w;
                pq.push({d[v][k-1], v});
                sort(d[v].begin(), d[v].end());
            }

        }
    }
}

int main()
{
    cin >> n >> m >> k;

    adja_list.resize(n+1);
    d.resize(n+1);

    for(int i=1; i<=n; i++){
        d[i].resize(k);
        for(int j=0; j<k; j++){
            d[i][j] = INF;
        }
    }


    d[1][0]=0;

    for(int i=0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
    }

    dijkstra(1);

    for(int i=0; i<k; i++){
        cout << d[n][i] << " ";
    }

    cout << "\n";
}


