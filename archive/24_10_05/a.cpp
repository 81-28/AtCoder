// https://atcoder.jp/contests/abc374/tasks/abc374_a

#include <bits/stdc++.h>
using namespace std;

#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main() {
    fastio();

    string s;
    cin >> s;
    int n = s.size();
    YesNo(s.substr(n-3,3) == "san");

    return 0;
}
