/*
During graph traversal we saw that there were two steps. One is selecting
a graph and the other is exploring the graph. During exploration of a node
all its adjacent nodes are “checked” and the already visited nodes are ignored.

Now we want to calculate how many times a particular node gets “checked”.
Modify the existing BFS algorithm to calculate how many times each of the nodes
get “checked”.

*/

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


BFS output -> 1 3 3 2 2



*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100;
bool visited[N];             //jei node visited hoye jabe oita 1 banaye dibo
vector<vector<int>> mat(N, vector<int>(N,0));
vector<int> checked(N);

void CheckedBFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int head = q.front();
        q.pop();
        cout << head << " ";

        for(int i=0 ; i<mat.size() ; i++){
            if(mat[head][i] == 1){
                checked[i]++;
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    cout << "\n";

}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    cout << "The matrix is \n";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "BFS";
    int src = 0;
    CheckedBFS(src);

    for(int i=0 ; i<n ; i++){
        if(i == src){
            continue;
        }
        cout << "Node " << i << ": checked " << checked[i] << " times" << "\n";
    }
}



