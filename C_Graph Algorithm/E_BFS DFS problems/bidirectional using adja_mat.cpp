/*

   0----1
   |\  /|
   | \/ |
   | /\ |
   |/  \|
   3----2

4 12
0 1
0 2
0 3
1 0
1 2
1 3
2 1
2 3
2 0
3 0
3 1
3 2


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<vector<int>> mat(N, vector<int>(N,0));
int n, m;

bool Bidirectional()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]==1 && mat[j][i]!=1){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        mat[u][v] = 1;
    }
    if(Bidirectional())
        cout << "YES";
    else
        cout << "NO";
}
