/*
1---->2
^
|     4---->5
|
3

5 3
1 2
3 1
4 5

Output
3 4 1 5 2
3 1 2 4 5

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];
vector<int> adja_list[N];
stack<int> st;

void DFS(int src)
{
    visited[src] = 1;
    for(int i: adja_list[src]){
        if(!visited[i]){
            DFS(i);
        }
    }
    st.push(src);  //kono node done holei stacke push korbo
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
    }

    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            DFS(i);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

