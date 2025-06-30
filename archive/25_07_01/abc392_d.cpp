// https://atcoder.jp/contests/abc392/tasks/abc392_d

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T>constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // m[i][j] : ダイスiでjが出る確率
    v<map<int,ld>> m(n);
    rep(i,n) {
        int k;
        cin >> k;
        vi a(k);
        cin >> a;
        map<int,int> mp;
        rep(j,k) ++mp[a[j]];
        for (auto p:mp) {
            m[i][p.f]=(ld)p.s/k;
        }
    }
    ld ans=0;
    for (int i=0; i+1<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int si=m[i].size(),sj=m[j].size();
            int idx=si<sj?i:j;
            int jdx=i+j-idx;
            ld sm=0;
            for (auto p:m[idx]) {
                if (m[jdx].find(p.f)!=m[jdx].end()) {
                    sm+=p.s*m[jdx][p.f];
                }
            }
            chmax(ans,sm);
        }
    }
    cout<<fixed<<setprecision(20);
    print(ans);

    return 0;
}
