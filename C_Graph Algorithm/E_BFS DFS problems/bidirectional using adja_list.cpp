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
vector<int> adja_list[N];
int n, m;

bool Bidirectional()
{
    for(int i=0 ; i<n ; i++){
        for(int j:adja_list[i]){
            bool found = false;   //reverse edge paile true hbe
            for(int k:adja_list[j]){
                if(k==i){
                    found = true;
                }
            }
            if(!found){
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

        adja_list[u].push_back(v);

    }
    if(Bidirectional())
        cout << "YES";
    else
        cout << "NO";

}

