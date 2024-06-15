#include<bits/stdc++.h>
using namespace std;

/*
  0---1
     / \
    /   \
   2-----3
*/

int main()
{
    //m= number of nodes
    //n= number of edges
    //u= pair.first
    //v= pair.second
    int m,n,u,v;
    cin >> n >> m;
    vector<pair<int, int>> edge_list;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        edge_list.push_back({u,v});
    }

    cout << "The edge list: \n";
    for(auto i:edge_list){
        cout << "[" << i.first << "," << i.second << "]\n";
    }

    cout << "Converting edge list to matrix: \n";
    vector<vector<int>> mat(n,vector<int>(n,0));  // this create a matrix row(n) and
    for(auto i:edge_list){                        // column(n) and set every value 0
       u = i.first;
       v = i.second;

       mat[u][v] = 1;
       mat[v][u] = 1;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
