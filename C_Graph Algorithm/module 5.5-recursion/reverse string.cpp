#include<bits/stdc++.h>
using namespace std;

void Reverse(string s)
{
    if(s.size()==0)
        return;
    Reverse(s.substr(1));
    cout << s[0];
}

int main()
{
    string s;
    cin >> s;
    Reverse(s);
}
