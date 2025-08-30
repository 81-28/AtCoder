// https://atcoder.jp/contests/abc421/tasks/abc421_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    queue<int> a,b;
    rep(i,n*2) {
        if (s[i]=='A') a.push(i);
        else b.push(i);
    }
    queue<int> aa=a,bb=b;
    int ans=LLONG_MAX,res=0;
    rep(i,n*2) {
        if (i%2) {
            int j=aa.front();
            aa.pop();
            int ad=max(i-j,0LL);
            res+=ad;
        } else {
            int j=bb.front();
            bb.pop();
            int ad=max(i-j,0LL);
            res+=ad;
        }
    }
    chmin(ans,res);
    res=0;
    rep(i,n*2) {
        if (i%2) {
            int j=b.front();
            b.pop();
            int ad=max(i-j,0LL);
            res+=ad;
        } else {
            int j=a.front();
            a.pop();
            int ad=max(i-j,0LL);
            res+=ad;
        }
    }
    chmin(ans,res);
    print(ans);

    return 0;
}
