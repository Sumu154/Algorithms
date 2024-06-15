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

long long Stair(int n)
{
    //1.handle base case
    if(n <= 2)
        return n;

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    long long ans = Stair(n-1)+Stair(n-2);
    dp[n] = ans;

    return ans;

}

int main()
{
    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        dp[i] = -1;
    }

    cout << Stair(n);

}
