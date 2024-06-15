#include<bits/stdc++.h>
using namespace std;

char getCapital(string s)
{
    char ch=s[0];
    if(ch>='A' && ch<='Z')  //basse case
        return ch;
    return getCapital(s.substr(1));

}


int main()
{
    string s;
    cin >> s;
    char ch = getCapital(s);
    cout << ch;
}
