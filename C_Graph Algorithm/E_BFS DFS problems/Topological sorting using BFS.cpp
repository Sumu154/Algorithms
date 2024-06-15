/*
1---->2
^
|     4---->5
|
3

5 3
1 2
3 1
4 5

Output 3 4 1 5 2
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N];
vector<int> adja_list[N];
stack<int> st;

