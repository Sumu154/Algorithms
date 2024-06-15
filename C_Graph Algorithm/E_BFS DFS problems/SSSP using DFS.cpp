/*
   0-----1-----2-----3
         |     |
         |     |
         5-----4

no of nodes = 6
no of edges = 6

list of adja_list

6 6

0 1
1 2
2 3
1 5
2 4
5 4


BFS output ->  0 1 2 5 3 4

*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100;
bool visited[N];
int level[N];
vector<int> adja_list[N];

void DFS(int src,int curr)
{
    visited[src] = 1;
    level[src] = curr;
    for(int i: adja_list[src]){
        if(visited[i] == 0){
            DFS(i, curr+1);
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    cout << "The adja list \n";
    for(int i=0 ; i<n ; i++){
        cout << i << "-> ";
        for(int j=0 ; j<adja_list[i].size() ; j++)
        {
            cout << adja_list[i][j] << " ";
        }
        cout << "\n";
    }

    int src = 7;
    DFS(src, 0);

    for(int i=0 ; i<n ; i++){
        cout << level[i] << " ";
    }
}
