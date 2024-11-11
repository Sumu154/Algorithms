#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
int level[N];    //path number rakhar jonno
vector<int> adja_list[N]; //grpagh ta rakhar jonno
int n, m;

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
            if(visited[i] == 0){
                visited[i] = true;
                level[i] = level[head]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int t, cs=1;
    cin >> t;
    while(t--){
        cin >> n >> m;

        for(int i=0 ; i<m ; i++){
            int u, v;
            cin >> u >> v;

            adja_list[u].push_back(v);
        }

        int src, dst;
        cin >> src >> dst;
        BFS(src);

        cout << "Case " << cs++ << ": " << level[dst] << "\n";
        for(int i=0 ; i<N ; i++){
            adja_list[i].clear();
        }
        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));
    }
}
