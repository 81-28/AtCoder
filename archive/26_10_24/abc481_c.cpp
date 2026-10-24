// https://atcoder.jp/contests/abc481/tasks/abc481_c

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    map<string,int> m;
    int i=0;
    while (q--) {
        string s;
        cin >> s;
        if (!m[s]) m[s]=++i;
        print(m[s]);
    }

    return 0;
}
