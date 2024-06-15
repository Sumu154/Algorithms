#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> parent(N);
vector<int> size(N);
vector<int> level(N);

/*
input 
7 5
1 2
2 3
4 5
5 6
1 4

output  5 5

*/

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

void UnionBySize(int u, int v)
{
    int lu = Find(u);
    int lv = Find(v);

    if(lu != lv){
        if(size[lu] > size[lv]){
            parent[lv] = lu;               //parent er size baraye dici
            size[lu] += size[lv];
        }
        else{
            parent[lu] = lv;     // lv ta hocce parent and size lv er barbe 
            size[lv] += size[lu];             //as lv er undere lu er node gula ashbe
        }
    }
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

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    Initialize(n+1);

    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        UnionBySize(u, v);
        //UnionByRank(u, v);
    }

    cout << Find(1) << " " << Find(4) << "\n";
}
