// https://atcoder.jp/contests/abc260/tasks/abc260_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,x,y,z;
    cin >> n >> x >> y >> z;
    vi a(n),b(n);
    cin >> a >> b;
    v<tuple<int,int,int>> p(n);
    rep(i,n) p[i]={-a[i],i+1,-b[i]};
    vi ans;
    sort(all(p));
    v<tuple<int,int,int>> q;
    int k=0;
    for (auto[a,j,b]:p) {
        if (k++<x) ans.pb(j);
        else q.pb({b,j,a+b});
    }
    sort(all(q));
    v<pii> r;
    k=0;
    for (auto[b,j,c]:q) {
        if (k++<y) ans.pb(j);
        else r.pb({c,j});
    }
    sort(all(r));
    k=0;
    for (auto[c,j]:r) {
        if (k++<z) ans.pb(j);
    }
    sort(all(ans));
    for (int val:ans) print(val);

    return 0;
}
