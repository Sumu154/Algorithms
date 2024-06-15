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
    vector<int> adja_list[n];

    //O(2*edge) = O(edge) = O(n^2)
    //1)undirected+unweighted
    adja_list[0] = {1};
    adja_list[1] = {2,3};
    adja_list[2] = {1,3};
    adja_list[3] = {1,2};

    //2)directed
    adja_list[0] = {1};
    adja_list[1] = {2};
    adja_list[2] = {};
    adja_list[3] = {1,2};

    //O(2*edge) = O(edge) = O(n^2)
    for(int i=0 ; i<n ; i++){
        cout << i << "-> ";
        for(int j=0 ; j<adja_list[i].size() ; j++)
        {
            cout << adja_list[i][j] << " ";
        }
        cout << "\n";
    }


    //weighted
//    vector<pair<int, int>> adja_list[n];
//    adja_list[0].push_back({1,2});
//    adja_list[1].push_back({2,4});
//    adja_list[3].push_back({2,4});
//    adja_list[3].push_back({1,7});
//
//    //O(2*edge) = O(edge) = O(n^2)
//    for(int i=0 ; i<n ; i++){
//        cout << i << "-> ";
//        for(int j=0 ; j<adja_list[i].size() ; j++)
//        {
//            cout << "(" << adja_list[i][j].first << "," << adja_list[i][j].second << ")";
//        }
//        cout << "\n";
//    }


}
