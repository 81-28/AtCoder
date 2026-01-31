// https://atcoder.jp/contests/abc280/tasks/abc280_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    s.pb('.');
    int n=t.size();
    rep(i,n) {
        if (s[i]!=t[i]) {
            print(i+1);
            return 0;
        }
    }

    return 0;
}
