// https://atcoder.jp/contests/abc475/tasks/abc475_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,s,l;
    cin >> n >> s >> l;
    --s;
    vi a(n-1);
    cin >> a;
    vvi d(2,{0});
    for (int i=s+1; i<n; ++i) d[0].pb(d[0].back()+a[i-1]);
    for (int i=s-1; i>=0; --i) d[1].pb(d[1].back()+a[i]);
    int ans=0;
    rep(i,2) {
        int m=d[i].size();
        // 終着点を固定した時に、反対側で折り返せる最大を探す
        rep(j,m) {
            if (d[i][j]>l) break;
            int r=l-d[i][j];
            auto it=upper_bound(all(d[!i]),r/2);
            int res=it-d[!i].begin();
            chmax(ans,j+res);
        }
    }
    print(ans);

    return 0;
}
