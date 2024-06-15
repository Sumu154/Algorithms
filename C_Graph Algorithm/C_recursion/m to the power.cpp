#include<bits/stdc++.h>
using namespace std;

int power(int m, int n)
{
     if(n == 0)
        return 1;

    return m * power(m, n-1);

}
int main()
{
    int n, m;
    cin >> m >> n;
    cout << power(m, n);

    return 0;
}

