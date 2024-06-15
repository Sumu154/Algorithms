/*
https://leetcode.com/problems/climbing-stairs/

1.define state:
       Stair(n) -> cost of reaching n-th Stair from 1st one

2.recursive eqn from smaller sub problem
     Stair(i) = Stair(i-1)+Stair(i-2)

3.define base case
     Stair(1) = 1
     Stair(2) = 2

2
output 2

8
output 34

*/

/*
Complexity:
     time -> O(N)
     space -> O(N)
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
long long dp[N];   //nth step e koto way te otha jabe oi value thakbe ei array te

int main()
{
    int n;
    cin >> n;

    //1.handle base case
    dp[1] = 1;
    dp[2] = 2;

    //2.loop through the state and calculate
    for(int i=3 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[n];

}
