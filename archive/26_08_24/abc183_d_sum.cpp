// https://atcoder.jp/contests/abc183/tasks/abc183_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,w;
    cin >> n >> w;
    v<tuple<int,int,int>> q(n);
    int mx=0;
    for (auto&[s,t,p]:q) {
        cin >> s >> t >> p;
        chmax(mx,t);
    }
    vi sm(mx+1,0);
    for (auto[s,t,p]:q) {
        sm[s]+=p;
        sm[t]-=p;
    }
    rep(i,mx+1) {
        if (i) sm[i]+=sm[i-1];
        if (sm[i]>w) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
