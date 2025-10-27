// https://atcoder.jp/contests/abc332/tasks/abc332_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    vvi a(h,vi(w)),b=a;
    cin >> a >> b;
    vvi c(w,vi(h)),d=c;
    rep(i,h)rep(j,w) {
        c[j][i]=a[i][j];
        d[j][i]=b[i][j];
    }
    // sortして一致すれば良いと思ったが、sortして同じものになった行を区別できないので、これではできない
    // エッジケース例
    // 3 3
    // 1 2 3
    // 2 3 1
    // 3 1 2
    // 2 3 1
    // 3 1 2
    // 1 2 3
    v<pair<vi,int>> p(h),q(h);
    rep(i,h) {
        sort(all(a[i]));
        sort(all(b[i]));
        p[i]={a[i],i};
        q[i]={b[i],i};
    }
    sort(all(p));
    sort(all(q));
    bool ok=1;
    rep(i,h) {
        rep(j,w) {
            if (p[i].f[j]!=q[i].f[j]) {
                ok=0;
                break;
            }
        }
        if (!ok) break;
    }
    if (!ok) {
        print(-1);
        return 0;
    }
    int ans=0;
    vi vec(h);
    rep(i,h) vec[p[i].s]=q[i].s;
    rep(i,h-1)for(int j=i+1; j<h; ++j) {
        if (vec[i]>vec[j]) ++ans;
    }

    p=v<pair<vi,int>>(w),q=p;
    rep(j,w) {
        sort(all(c[j]));
        sort(all(d[j]));
        p[j]={c[j],j};
        q[j]={d[j],j};
    }
    sort(all(p));
    sort(all(q));
    ok=1;
    rep(j,w) {
        rep(i,h) {
            if (p[j].f[i]!=q[j].f[i]) {
                ok=0;
                break;
            }
        }
        if (!ok) break;
    }
    if (!ok) {
        print(-1);
        return 0;
    }
    vec=vi(w);
    rep(j,w) vec[p[j].s]=q[j].s;
    rep(i,w-1)for(int j=i+1; j<w; ++j) {
        if (vec[i]>vec[j]) ++ans;
    }
    print(ans);

    return 0;
}
