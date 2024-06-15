/*

1---->3
^    /^
|   / |
|  /  |
| v   |
2---->4

4 4
1 3
2 1
2 4
3 4

output -> No

4 5
1 3
2 1
2 4
3 4
3 2

output-> yes

1) visited[i] == 0 | unselected and unexplored => unvisited | apply DFS
2) visited[i] == 1 | selected   and unexplored => paused    | cycle detected
3) visited[i] == 2 | selected   and explored   => done      | continue

*/


#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
vector<int> adja_list[N]; //grpagh ta rakhar jonno

bool DFS(int src)
{
    visited[src] = 1;
    for(int i: adja_list[src]){
       if(visited[i]==0){
           if(DFS(i)){
                return true;
           }
       }
       else if(visited[i]==1){
           return true;
       }
       //visited[i]=2 hole emitei continue hbe
    }
    visited[src] = 2;
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
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            bool cycle = DFS(i);
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
