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

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int i:adja_list[head]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
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
        if(!visited[i]){
            count++;
            BFS(i);
        }
    }

    cout << count;
}
