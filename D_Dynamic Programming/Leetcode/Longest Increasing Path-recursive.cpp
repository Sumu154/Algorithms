/*
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

3 3
9 9 4
6 6 8
2 1 1
output
4
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 201;

int n, m;
int matrix[N][N];
int dp[N][N];

int solve(int i, int j, int last){
    //base case
    if(i<0 || i>=n || j<0 || j>=m){
        return 0;
    }
    if(last >= matrix[i][j]){         // check the bigger number
        return 0;
    }

    //check the previous existance
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up    = 1 + solve(i-1, j, matrix[i][j]);
    int down  = 1 + solve(i+1, j, matrix[i][j]);
    int right = 1 + solve(i, j+1, matrix[i][j]);
    int left  = 1 + solve(i, j-1, matrix[i][j]);

    int ans1 = max(up, down);
    int ans2 = max(right, left);

    int ans = max(ans1, ans2);
    dp[i][j] = ans;
    return ans;
}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, solve(i, j, -1));
        }
    }
    cout << ans << endl;
}

