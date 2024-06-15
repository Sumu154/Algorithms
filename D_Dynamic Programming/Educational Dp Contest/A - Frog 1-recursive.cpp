/*
1.define state:
       stone(n) -> cost of reaching n-th stone from 1st one

2.recursive eqn from smaller sub problem
     stone(i) = min (stone(i-1) + abs(h[i]-h[i-1]),
                     stone(i-2) + abs(h[i]-h[i-2])
                    )
3.define base case
     stone(1) = 0

4
10 30 40 20

output
30     <=|10-30|+|30-20|

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int h[N];
int dp[N];  //solved case gulak rakhar jonno

int Stone(int n)
{
    //1.handle base case
    if(n==1){
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1){
        return dp[n];
    }

    //3.calculate the result from smaller sub problem
    int ans1 = Stone(n-1) + abs(h[n]-h[n-1]);
    //**handle corner case
    if(n==2){
        dp[n] = ans1;
        return ans1;
    }
    int ans2 = Stone(n-2) + abs(h[n]-h[n-2]);
    int ans = min(ans1, ans2);

    dp[n] = ans;
    return ans;

}

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> h[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << Stone(n) << "\n";


}

