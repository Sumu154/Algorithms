#include<bits/stdc++.h>
using namespace std;

int Sum(int num)
{
    if(num==0)
        return num;
    int rem = num%10;
    num = num/10;
    return rem+Sum(num);
}

int main()
{
    int num;
    cin >> num;
    int sum = Sum(num);
    cout << sum;
}
