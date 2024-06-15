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

bool ConnectedBFS(int start, int target)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int head = q.front();
        q.pop();

        if(head == target){
            return true;
        }
        for(int i: adja_list[head]){
            if(!visited[i]){
               visited[i] = true;
               q.push(i);
            }
        }
    }
    return false;
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

    if(ConnectedBFS(start, target))
        cout << start << " and " << target << " are connected";
    else
        cout << start << " and " << target << " are not connected";
}


