/*
Take the following graph as input and determine whether nodes 2 and 6 are connected using BFS.
Use the code in this link to take input: https://ideone.com/t1OAZs

9 11
0 2
7 8
0 4
0 5
6 7
1 4
1 5
2 3
2 4
4 5
8 6
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 500;
int visited[N];
vector<int> adja_list[N];

bool ConnectedDFS(int start, int target)
{
    if(start == target){
        return true;
    }
    visited[start] = 1;
    for(int i: adja_list[start]){
        if(!visited[i]){
            if(ConnectedDFS(i,target)){
                return true; // Found a path from neighbor to targetNode
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

    int start = 0;
    int target = 5;

    if(ConnectedDFS(start, target)){
        cout << start << " and " << target << " are connected";
    }
    else{
        cout << start << " and " << target << " are not connected";
    }
}
