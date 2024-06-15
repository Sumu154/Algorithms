/*
https://leetcode.com/problems/house-robber/

1.define state
     Robber(n) -> max amount of money from 1 to n house

2.recursive eqn from smaller sub problem
     Robber(n) = max(Robber(n-1) + 0,
                     Robber(n-2) + house(n)
                     )

3.define base case
    Robber(0) = 0

4
1 2 3 1

output
4

5
2 7 9 3 1

output
12


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];  //n porjonto min cost rakhr jonno
int house[N];

int Robber(int n)
{
    //1.handle base case
    if(n <= 0)
        return 0;


    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    int ans1 = Robber(n-1) + 0;
    int ans2 = Robber(n-2) + house[n];
    int ans = max(ans1, ans2);

    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> house[i];
    }

    for(int i=1 ; i<=n ; i++){
        dp[i] = -1;
    }

    cout << Robber(n);
}

