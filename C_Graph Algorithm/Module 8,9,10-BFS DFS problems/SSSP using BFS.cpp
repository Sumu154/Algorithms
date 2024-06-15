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


BFS output ->  0 1 2 3 3 2


time complexity -> O(V+E)
space complexity -> O(v+E)

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
int level[N];    //path number rakhar jonno
vector<int> adja_list[N]; //grpagh ta rakhar jonno


void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    level[src] = 0;      //source to source = 0 node

    while(!q.empty()){
        int head = q.front();
        q.pop();
        cout << head << " ";

        for(int i: adja_list[head]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                level[i] = level[head]+1;
            }
        }
    }
    cout << "\n";
}

int main()
{
    //n = num of nodes
    //m = num of edges
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);

    }


    int src = 0;
    cout << "BFS ";
    BFS(src);

    for(int i=0 ; i<n ; i++){
        cout << "node " <<  i << " : level " << level[i] << "\n";
    }
    cout << "\n";

}

