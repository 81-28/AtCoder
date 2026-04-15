// https://atcoder.jp/contests/abc256/tasks/abc256_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define pb push_back


template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> mp;
    while (n--) {
        int l,r;
        cin >> l >> r;
        ++mp[l],--mp[r];
    }
    v<pii> ans;
    int sm=0;
    for (auto[i,cnt]:mp) {
        if (sm==0) ans.pb({i,0});
        sm+=cnt;
        if (sm==0) ans.back().second=i;
    }
    for (pii p:ans) print(p);

    return 0;
}
