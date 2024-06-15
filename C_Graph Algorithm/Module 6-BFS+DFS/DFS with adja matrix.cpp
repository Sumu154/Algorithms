/*
Rewrite DFS in C++ but this time use an adjacency matrix as graph representation
 instead of adjacency list. Analyse the time and space complexity.
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];
vector<vector<int>> mat(N,vector<int> (N,0));

void DFS(int src)
{
    visited[src] = 1;
    cout << src << " ";
    for(int i=0; i <mat.size(); i++){
        if(mat[src][i]==1 and !visited[i]){
            DFS(i);
        }
    }
}

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

0 1 0 0 0 0
1 0 1 0 0 1
0 1 0 1 1 0
0 0 1 0 0 0
0 0 1 0 0 1
0 1 0 0 1 0


BFS output ->  0 1 2 3 4 5

*/

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    cout << "\nThe matrix is \n";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int src = 0;
    cout << "DFS ";
    DFS(src);

}
