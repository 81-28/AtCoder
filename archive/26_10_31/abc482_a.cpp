// https://atcoder.jp/contests/abc482/tasks/abc482_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int sm=0;
    for (char c:s) {
        if (c=='o') ++sm;
    }
    print(sm&1?"odd":"even");

    return 0;
}
