// https://atcoder.jp/contests/abc285/tasks/abc285_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    rep1(i,n-1) {
        int l=1;
        for (; l+i<=n; ++l) {
            if (s[l-1]==s[l+i-1]) break;
        }
        print(l-1);
    }

    return 0;
}
