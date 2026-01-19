// https://atcoder.jp/contests/abc282/tasks/abc282_c

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    bool b=1;
    for (char&c:s) {
        if (c=='"') b^=1;
        if (c==','&&b) c='.';
    }
    print(s);

    return 0;
}
