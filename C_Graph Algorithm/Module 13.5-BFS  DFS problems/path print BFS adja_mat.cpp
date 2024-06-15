/*
    2-----3
     \   /
      \ /
       1
       |
       |
       4----5

5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
vector<int> parent(N, -1);
vector<vector<int>> mat(N, vector<int>(N,0));
int n, m;

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] =1;
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
            if (mat[head][i] && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
                parent[i] = head;
            }
        }
    }
}

void print_path()
{
    vector<int> path;
    while(n != -1)
    {
        path.push_back(n);
        n = parent[n];
    }
    cout << path.size() << "\n";
    reverse(path.begin(), path.end());

    for(int i: path){
        cout << i << " ";
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;

    }

    int source = 1;
    BFS(source);

    if(visited[n])
        print_path();

    else
        cout << "IMPOSSIBLE";

}


