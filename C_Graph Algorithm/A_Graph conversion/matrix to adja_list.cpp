#include<bits/stdc++.h>
using namespace std;

/*
  0---1
     / \
    /   \
   2-----3

4 4

0 1
1 2
2 3
1 3

*/

//undirected+unweighted
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n,0));
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    cout << "The matrix is: \n";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "converting matrix to list: \n";
    vector<int> adja_list[n];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
        {
            if(mat[i][j] == 1)
            {
                adja_list[i].push_back(j);
            }
        }
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
