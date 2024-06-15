/*
Take the following graph as input and determine whether nodes 2 and 6 are connected using BFS.
Use the code in this link to take input: https://ideone.com/t1OAZs

9 11
0 2
7 8
0 4
0 5
6 7
1 4
1 5
2 3
2 4
4 5
8 6
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 500;
vector<int> adja_list[N];

bool Connected(int start, int target)
{
    for(int i: adja_list[start]){
        if(i==target){
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    int start = 0;
    int target = 5;

    if(Connected(start, target))
        cout << start << " and " << target << " are connected";
    else
        cout << start << " and " << target << " are not connected";
}



