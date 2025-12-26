// https://atcoder.jp/contests/joisc2014/tasks/joisc2014_h

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // jを基準とした差{o,i}となる位置
    map<pii,vi> mp;
    // o,jのiに対する相対個数
    pii cnt(0,0);
    mp[cnt].pb(0);
    rep(k,n) {
        auto&[o,i]=cnt;
        if (s[k]=='J') {
            --o,--i;
        }
        if (s[k]=='O') ++o;
        if (s[k]=='I') ++i;
        mp[cnt].pb(k+1);
    }
    // 相対個数が一致する最大距離
    int ans=0;
    for (auto[p,i]:mp) chmax(ans,*i.rbegin()-*i.begin());
    print(ans);

    return 0;
}
