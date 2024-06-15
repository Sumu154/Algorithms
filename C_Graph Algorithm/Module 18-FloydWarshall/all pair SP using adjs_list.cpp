/*
4 3
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2


*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1000;

const int N = 100;
int d[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            d[i][j] = INF;
        }
    }

    for(int i=0 ; i<m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for(int i=1 ; i<=n ; i++){
        d[i][i] = 0;
    }

    for(int k=1 ; k<=n ; k++){     //intermidiate mode 1...k dhore
        for(int u=1 ; u<=n ; u++){
            for(int v=1 ; v<=n ; v++){
                d[u][v] = min(d[u][v], d[u][k]+d[k][v]);
            }
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(d[i][j] == INF){
                cout << "INF ";
            }
            else{
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }

}
