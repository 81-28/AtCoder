// https://atcoder.jp/contests/abc477/tasks/abc477_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n),b(n);
    cin >> a >> b;

    vi sm(n+1,0);
    rep(i,n) sm[i+1]=sm[i]+a[i];

    priority_queue<pii,v<pii>,greater<>> qu;
    rep(i,n) qu.push({b[i],i});
    while (!qu.empty()) {
        auto[dist,pos]=qu.top();
        qu.pop();
        if (b[pos]<dist) continue;
        int i=(pos+n-1)%n;
        int j=(pos+1)%n;
        if (chmin(b[i],dist+a[(pos+n-1)%n])) qu.push({b[i],i});
        if (chmin(b[j],dist+a[pos])) qu.push({b[j],j});
    }

    // 途中で頂点n+1を通るとしても高々1回
    // s -> t
    // s -> n+1 -> t
    // のパターンしかないので、
    // それぞれの点の、n+1からの最短距離を先に求めておく
    while (q--) {
        int l,r;
        cin >> l >> r;
        --l,--r;
        if (r==n) {
            print(b[l]);
            continue;
        }
        int ans=sm[r]-sm[l];
        chmin(ans,sm[n]-ans);
        chmin(ans,b[l]+b[r]);
        print(ans);
    }

    return 0;
}
