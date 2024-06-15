 #include<bits/stdc++.h>
using namespace std;

/*

  0---1
     / \
    /   \
   2-----3


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

   mat[i][j]=1 if and only if i-->j ekta way thake

   n nodes->maximum number of edge = n^2
      when every node has edge with every node
*/

int main()
{
    int n = 4;
    int mat[n][n];
    for(int i=0 ; i<n ; i++){    //O(n^2)
        for(int j=0 ; j<n ; j++)
        {
            mat[i][j] = 0;
        }
    }

    mat[0][1] = 4;
    mat[1][0] = 4;

    mat[1][2] = 1;
    mat[2][1] = 1;

    mat[2][3] = 2;
    mat[3][2] = 2;

    mat[3][1] = 3;
    mat[1][3] = 3;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
