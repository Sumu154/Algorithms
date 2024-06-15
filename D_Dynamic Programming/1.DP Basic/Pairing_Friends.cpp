/*
1.define state
     PairOfFriends(n) -> number of ways to make groups for n people

2.recursive eqn from smaller sub problem
     PairOfFriends(n) = 1*PairOfFriends(n-1) +
                        (n-1)*PairOfFriends(n-2)

3.define base case
     PairOfFriends(1) = 0

11
output
4

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];

int PairOfFriends(int n)
{
    //1.handle base case
    if(n<=2){
        return n;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1){
        return dp[n];
    }

    //3.calculate the result from smaller sub problem
    int ans1 = PairOfFriends(n-1);        //n jodi single thake
    int ans2 = (n-1)*PairOfFriends(n-2);     //jodi pair kore
    int ans = ans1+ans2;

    dp[n] = ans;          //memorize -> save kore rakhbo calculated value gula
    return ans;
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << PairOfFriends(n);
}

