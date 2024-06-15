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
    int n,num,val;
    cin >> n;
    vector<int> adja_list[n];
    for(int i=0 ; i<n ; i++){
        cin >> num;
        cout << i << "-> ";
        for(int j=0 ; j<num ; j++)
        {
            cin >>  val;
            adja_list[i].push_back(val);
        }
    }

    cout << "The list is: \n";
    for(int i=0 ; i<n ; i++){
        cout << i << "->";
        for(int j=0 ; j<num ; j++)  //num=adja_list.size()
        {
            cout << adja_list[i][j] << ",";
        }
        cout << "\n";
    }

    cout << "Converting list to matrix: \n";        //2D vector called `matrix`with a size
    vector<vector<int>> mat(n,vector<int>(n,0));    //of `nodes` by `nodes`.Each element of
        for(int i=0 ; i<n ; i++){                   //the `matrix` is initialized to 0
        for(auto j: adja_list[i])
        {
            mat[i][j] = 1;
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

}
