#include<bits/stdc++.h>
using namespace std;

/*
  0---1
     / \
    /   \
   2-----3

  0-->1
     / ^
    V   \
   2<----3

     4
  0---1
     / \ 3
 1  /   \
   2-----3
      2




   total node = 4
   total edge = 4

   *undirected
   *unweighted

   0-> 1
   1-> 2,3
   2-> 1,3
   3-> 1,2

   mat[i][j]=1 if and only if i-->j ekta way thake

   n nodes->maximum number of edge = n^2
      when every node has edge with every node
*/

int main()
{
    int n=4;
    vector<vector<int>> edge_list;
    edge_list.push_back({0,1});
    edge_list.push_back({1,2});
    edge_list.push_back({1,3});
    edge_list.push_back({2,3});

    for(int i=0 ; i<edge_list.size() ; i++){
        cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
    }
}
