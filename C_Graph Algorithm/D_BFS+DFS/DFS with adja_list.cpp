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


DFS output -> 0 1 2 3 4 5

*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
vector<int> adja_list[N]; //grpagh ta rakhar jonno

void DFS(int src)
{
    cout << src << " ";
    visited[src] = 1;
    for(int i: adja_list[src]){
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main()
{
    //n = num of nodes
    //m = num of edges
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);

    }

    cout << "\nThe adja list \n";
    for(int i=0 ; i<n ; i++){
        cout << i << "-> ";
        for(int j=0 ; j<adja_list[i].size() ; j++)
        {
            cout << adja_list[i][j] << ",";
        }
        cout << "\n";
    }
    cout << "\n";

    int src = 0;
    cout << "DFS ";
    DFS(src);
}


