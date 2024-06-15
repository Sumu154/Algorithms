/*
           4
     1      \    6
    / \      \
   /   \      \
  /     \      5
 2-------3


6 4

1 2
2 3
1 3
4 5

output -> 3

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];
vector<int> adja_list[N];

void DFS(int source)
{
    visited[source] = 1;
    for(int i:adja_list[source]){
        if(visited[i] == 0)
        {
            DFS(i);
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

    int count = 0;
    for(int i=1 ; i<=n ; i++){
        if(visited[i] == 0)
        {
            count++;
            DFS(i);
        }
    }
    cout << count;
}
