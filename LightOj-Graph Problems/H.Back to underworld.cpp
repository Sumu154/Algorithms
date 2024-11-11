#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int> adjList[N];
int visited[N];
int color[N];

void Clear(){
    for(int i=0; i<N; i++){
        adjList[i].clear();
        visited[i] = 0;
        color[i] = -99;
    }
}

long long bfs(long long src){
    long long vm=0, lk=0;

    queue<long long> q;
    q.push(src);

    visited[src] = 1;
    vm++;
    color[src] = 1;

    while(!q.empty()){
        long long head = q.front();
        q.pop();

        for(auto i: adjList[head]){
            if(visited[i] == 0){
                visited[i] = 1;
                q.push(i);

                if(color[head] == 1){
                    color[i] = 0;
                    lk++;
                }
                else{
                    color[i] = 1;
                    vm++;
                }
            }
        }
    }

    return max(vm, lk);
}

int main(){
    int t, cs=1;
    cin >> t;

    while(t--){
        Clear();

        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        long long res = 0;
        for(int i=0; i<N; i++){
            if(visited[i]==0  &&  !adjList[i].empty()){
                res += bfs(i);
            }
        }
        cout << "Case " << cs++ << ": "  << res << endl;
    }
}
