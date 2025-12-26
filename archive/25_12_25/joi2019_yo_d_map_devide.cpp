// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n+2,-1);
    map<int,v<pii>> mp;
    // 0が無いと初期状態の計算が行われない
    mp[0];
    rep1(i,n) {
        cin >> a[i];
        if (mp[a[i]].size()) {
            auto&[l,r]=*mp[a[i]].rbegin();
            if (r+1==i) ++r;
            else mp[a[i]].pb({i,i});
        } else mp[a[i]].pb({i,i});
    }
    int mx=0,ans=1;
    // 高さhが沈む
    for (auto[h,vec]:mp) {
        for (auto[l,r]:vec) {
            if (a[l-1]>h && h<a[r+1]) ++ans;
            if (a[l-1]<h && h>a[r+1]) --ans;
        }
        chmax(mx,ans);
    }
    print(mx);

    return 0;
}
