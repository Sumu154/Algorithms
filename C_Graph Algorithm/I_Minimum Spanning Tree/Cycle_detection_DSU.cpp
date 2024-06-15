#include<bits/stdc++.h>
using namespace std;

/*
4 3
0 1
0 2
0 3

output NO

4 4
0 1
0 2
0 3
2 3

output YES

*/

const int N = 1e5+5;
vector<int> parent(N);
vector<int> size(N);
vector<int> level(N);

//only undirected grapher jonno kaj kore,,directed hole kaj kore na

void Initialize(int n)
{
    for(int i=0 ; i<=n ; i++){
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
    int leader = Find(parent[u]);
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

    int cycle =  false;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        
        int lu = Find(u);
        int lv = Find(v);
        if(lu == lv){
            cycle = true;
        }
        else{
            UnionBySize(u, v);
        }
    }

    if(cycle){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

}
