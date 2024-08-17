// https://atcoder.jp/contests/abc367/tasks/abc367_a

#include <bits/stdc++.h>
using namespace std;

#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    YesNo((c < a && a < b) || (b < c && (a < b || c < a)));

    return 0;
}
