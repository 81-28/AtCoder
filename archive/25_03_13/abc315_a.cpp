// https://atcoder.jp/contests/abc315/tasks/abc315_a

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    cout<<regex_replace(s,regex("[aeiou]"),"");
}
