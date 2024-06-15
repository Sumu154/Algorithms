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
    int n,m,u,v;
    cin >> n >> m;
    vector<pair<int, int>> edge_list;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        edge_list.push_back({u,v});
    }

    cout << "The edge list \n";
    for(auto i:edge_list){
        cout << "[" << i.first << "," << i.second << "]\n";
    }

    cout << "Converting edge list to adja list\n";
    vector<int> adja_list[n];
    for(auto i:edge_list){
        u = i.first;
        v = i.second;
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }
    for(int i=0 ; i<n ; i++){
        cout << i << "-> ";
        for(int j=0 ; j< adja_list[i].size() ; j++)
        {
            cout << adja_list[i][j] << ",";
        }
        cout << "\n";
    }

}
