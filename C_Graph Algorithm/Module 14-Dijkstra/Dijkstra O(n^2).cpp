/*

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


*/



#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

const int N = 1e5+5;
int visited[N];
vector<long long> d(N, INF);
vector<pair<int, int>> adja_list[N];
int n, m;

void dijkstra(int source)
{

    d[source] = 0;

    for(int i=0; i<n; i++){
        int selected = -1;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]==1)
                continue;

            if(selected == -1  || d[selected] > d[j])
                selected = j;
        }

        visited[selected] = 1;

        for(auto i: adja_list[selected])
        {
            int node = i.first;
            int weight = i.second;

            if(d[selected] + weight  < d[node])
                d[node] = d[selected] + weight;
        }
    }

}

int main(){


    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
        adja_list[v].push_back({u,w});
    }

    int source = 1;
    dijkstra(source);

    for(int i=1 ; i<=n ; i++){
        cout << d[i] << " ";
    }
}

