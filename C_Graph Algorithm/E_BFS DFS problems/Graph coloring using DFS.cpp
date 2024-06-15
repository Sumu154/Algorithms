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

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];
int color[N];
vector<int> adja_list[N];


bool DFS(int src)              //i ke source dhore DFS chalanor pore jodi
{                                 //bi colorable hoy tahole true return korbe
    visited[src] = 1;
    for(int i:adja_list[src]){
        if(visited[i] == 0)
        {
            //assign a ditterent color to adja node
            if(color[src] == 1)
                color[i] = 2;
            else
               color[i] = 1;

            bool is_bicolorabe = DFS(i);
            if(!is_bicolorabe)
                return false;
        }
        else
        {
            //check if the colore is same or different
            if(color[src] == color[i])
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        long long int u, v;
        cin >> u >> v;

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    bool is_bicolorabe = true;
    for(int i=1 ; i<=n ; i++){
        if(visited[i] == 0)
        {
            color[i] = 1;
            bool ok = DFS(i);
            if(!ok)
            {
                is_bicolorabe = false;
                break;
            }
        }
    }

    if(!is_bicolorabe)
        cout << "IMPOSSIBLE";
    else
    {
        cout << "POSSIBLE\n";
        for(int i=1 ; i<=n ; i++){
            cout << color[i] << " ";
        }
    }
}
