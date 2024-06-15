#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> parent(N);
vector<int> size(N);
vector<int> level(N);

/*
5 7
0 1 2
0 2 3
0 3 3
2 4 4
2 1 7
1 4 5
3 4 6


*/

class edge{
public:
    int u, v, w;

    edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }

};


void Initialize(int n)
{
    for(int i=1 ; i<=n ; i++){
        parent[i] = -1;
        size[i] = 1;
        level[i] = 0;
    }
}

int Find(int u)
{
    if(parent[u] == -1){
        return u;
    }
    int leader = Find(parent[u]);    // eta mainly path compression kore
    parent[u] = leader;
    return leader;
}

void UnionByRank(int u, int v)
{
    int lu = Find(u);
    int lv = Find(v);

    if(lu != lv){
        if(level[lu] > level[lv]){
            parent[lv] = lu;    
        }
        else if(level[lu] < level[lv]){
            parent[lu] = lv;   
        }
        else{
            parent[lu] = lv;
            level[lv]++;
        }
    }
}


bool comp(edge a, edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Initialize(n);
    vector<edge> edge_list;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;

        edge_list.push_back({edge(u, v, w)});
    }


    sort(edge_list.begin(), edge_list.end(), comp);

    int totalCost = 0;
    for(edge i: edge_list){
        int leaderU = Find(i.u);
        int leaderV = Find(i.v);

        if(leaderU == leaderV){
            continue;
        }
        else{
            UnionByRank(i.u, i.v);
            totalCost += i.w;
        }
    }
    
    cout << totalCost << "\n";

}