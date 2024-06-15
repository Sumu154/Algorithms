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

const int N = 2e5;
int visited[N];
vector<int> adja_list[N];
vector<int> parent(N, -1);
int n, m;

void DFS(int src)
{
    visited[src] = 1;
    for(int i: adja_list[src]){
        if(!visited[i]){
            parent[i] = src;
            DFS(i);
        }
    }
}

void print_path()
{
    vector<int> path;
    while(n != -1){
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

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    int src = 1;
    DFS(src);

    if(visited[n]){
        print_path();
    }
    else{
        cout << "IMPOSSIBLE";
    }
}
