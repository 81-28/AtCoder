// https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_b

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


map<char,int> m={
    {'J',0},
    {'O',1},
    {'I',2}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    string s;
    cin >> n >> k >> s;
    vvi idx(3);
    rep(i,n) idx[m[s[i]]].pb(i);
    int ans=INF;
    // 最初のJの位置を固定
    // その位置からJをk個、その次の位置からOをk個、その次の位置からIをk個、貪欲に探す
    for (int i:idx[0]) {
        auto iti=lower_bound(all(idx[0]),i);
        iti+=k-1;
        if (iti>=idx[0].end()) continue;
        auto ito=lower_bound(all(idx[1]),*iti);
        ito+=k-1;
        if (ito>=idx[1].end()) continue;
        auto itj=lower_bound(all(idx[2]),*ito);
        itj+=k-1;
        if (itj>=idx[2].end()) continue;
        chmin(ans,*itj-i+1-k*3);
    }
    print(ans==INF?-1:ans);

    return 0;
}
