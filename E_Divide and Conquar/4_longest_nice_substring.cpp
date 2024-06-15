#include<bits/stdc++.h>
using namespace std;

/*
abxCDScsedEadB

output -> CDScsedE
*/


string longestNice(string s) 
{
    if(s.size() < 2){
        return "";
    }

    unordered_set<char> st;
    st.insert(s.begin(), s.end());

    for(int i=0 ; i<s.size() ; i++){
        char ch = s[i];

        char temp1 = toupper(ch);
        char temp2 = tolower(ch);

        if(st.find(temp1)==st.end() or st.find(temp2)==st.end()){   //s[i] er upper and lower er moddhe jodi
            string left = longestNice(s.substr(0,i));                     //kono ekta missing thake tobe
            string right = longestNice(s.substr(i+1));      //i+1 pos theke pura string tuku

            if(left.size()>=right.size()){
                return left;
            }
            else{
                return right;
            }
        }
    }

    return s;
}


int main()
{
   string s;
   cin >> s;
   cout << longestNice(s) << "\n";
}

