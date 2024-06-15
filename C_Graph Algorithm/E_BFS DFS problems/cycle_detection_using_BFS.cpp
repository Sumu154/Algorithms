/*

jhamela aceeeeeeeeeeeee

1---->3
^    /^
|   / |
|  /  |
| v   |
2---->4

4 5

1 3
2 1
2 4
3 2
3 4

output -> YES

1) visited[i] == 0 | unselected and unexplored => unvisited | apply DFS
2) visited[i] == 1 | selected   and unexplored => paused    | cycle detected
3) visited[i] == 2 | selected   and explored   => done      | continue

*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
vector<int> adja_list[N]; //grpagh ta rakhar jonno

bool BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int i: adja_list[head]){
            if(visited[i]==0){
                visited[i] = 1;
                q.push(i);
            }
            else if(visited[i]==1){
                return true;
            }
        }
        visited[head] = 2;
    }
    return false;
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;               //u --> v
        adja_list[u].push_back(v);
    }

   bool found = false;
    for(int i=1 ; i<=n ; i++){   //eker beshi component thakle
        if(visited[i] == 0){
            bool cycle = BFS(i);
            if(cycle){
                found = true;
                break;
            }
        }
    }
    if(found)
        cout << "YES";
    else
        cout << "NO";
}

