#include<bits/stdc++.h>
using namespace std;

const long long N = 10005;
vector<long long> adja_list[N];
set<int> s;
long long money[N];
long long visited[N];

bool BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    long long count = 1;
    long long sum = money[src];

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int i: adja_list[head]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);

                count++;
                sum += money[i];
            }
        }
    }

    if((sum%count) == 0){
        int ans = sum/count;
        s.insert(ans);
        return true;
    }
    return false;
}

int main()
{
    int t, cs=1;
    int n, m, u, v;
    cin >> t;
    while(t--){
        cin >> n >> m;

        for(int i=1 ; i<=n ; i++){
            cin >> money[i];
        }
        for(int i=0 ; i<m ; i++){
            cin >> u >> v;

            adja_list[u].push_back(v);
            adja_list[v].push_back(u);
        }

        cout << "Case "<< cs++ <<": ";
        bool flag = true;
        for(int i=1 ; i<=n ; i++){
            if(!visited[i]){
                bool ok = BFS(i);
                if(!ok){
                    flag = false;
                    cout << "No\n";
                    break;
                }
            }
        }
        if(flag){
            if(s.size()==1){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }

        for(int i=0 ; i<=n ; i++){
            visited[i] = 0;
            adja_list[i].clear();
            money[i] = 0;
        }  
        s.clear();
    }

}
