/*
https://leetcode.com/problems/house-robber-ii/description/

1.define state:
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

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int dp[N];
int a[N];
vector<int> start[N];
vector<int> last[N];

int Robber(int start, int last)
{
    //1.handle base case
    if(last == start)
        return a[start];

    //2.if current state is already solved,return the solved result
    if(dp[last] != -1)
        return dp[last];

    //3.calculate the result from smaller sub problem
    int ans1 = Robber(start, last-1) + 0;
    int ans2 = Robber(start, last-2) + a[last];
    int ans = max(ans1, ans2);

    dp[last] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }

    if(n==1)
    {
        cout << a[1];
        return 0;
    }
    if(n==2)
    {
        cout << max(a[1], a[2]);
        return 0;
    }
    if(n==3)
    {
        cout << max({a[1], a[2], a[3]});
        return 0;
    }

    //n er onno valuer jonno
    memset(dp, -1, sizeof(dp));
    int ans1 = Robber(1, n-1);

    memset(dp, -1, sizeof(dp));
    int ans2 = Robber(2, n);

    int ans = max(ans1, ans2);

    cout << ans;

}
