/*
1.define state:
     stone(n) -> cost of reaching n-th stone from 1st one

2.recursive eqn from smaller sub problem
     stone(i) = for(i=1 to k
                min (stone(i-1) + abs(h[i]-h[i-1]))

3.define base case
     stone(1) = 0

i <=== i-1, i-2, i-k
i<k -> impossible


time complexity -> O(n*k)
space complexity -> O(n)

5 3
10 30 40 50 20

output
30

*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 2e9;

const int N = 1e5+5;
int h[N];
int dp[N];
int n, k;

int Stone(int n)
{
    cout << n << "\n";
    //1.handle base case
    if(n==1){
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1){
        return dp[n];
    }

    //3.calculate the result from smaller sub problem
    int ans = INF;
    for(int i=1 ; i<=k ; i++){
        //**handle corner case
        if(n-i <= 0){
            break;
        }

        int candidate_ans = Stone(n-i) + abs(h[n]-h[n-i]);
        ans = min(candidate_ans, ans);
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++){
        cin >> h[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << Stone(n) << "\n";
}


