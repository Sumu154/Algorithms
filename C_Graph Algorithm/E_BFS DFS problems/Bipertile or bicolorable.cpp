/*

1---2
|     4---5
3

5 3
1 2
1 3
4 5

Output may be
1 2 2 1 2
1 2 2 2 1
2 1 1 2 1
2 1 1 2 1

bipertile = bicolorable

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];
int color[N];
vector<int> adja_list[N];


bool DFS(int src)
{
    visited[src] = true;
    for(int i: adja_list[src]){
        if(!visited[i]){
            if(color[src] == 1){
                color[i] = 2;
            }
            else{
                color[i] = 1;
            }
            bool is_bicolorabe = DFS(i);
            if(!is_bicolorabe){
                return false;
            }
        }
        else{
            if(color[src] == color[i]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    bool is_bicolorabe = true;
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            color[i] = 1;
            bool ok = DFS(i);
            if(!ok){
                is_bicolorabe = false;
                break;
            }
        }
    }

    if(!is_bicolorabe){
        cout << "Not Bipartite and Bicolorable";
    }
    else{
        cout << "Bipartite and Bicolorable";
    }
}

