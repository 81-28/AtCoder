// https://atcoder.jp/contests/abc374/tasks/abc374_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<class T>constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    double sp,t;
    cin >> n >> sp >> t;
    v<pair<pii,pii>> a(n);
    rep(i,n) cin >> a[i];
    int mx=pow(2,n);
    sort(all(a));
    double ans=DBL_MAX;
    do {
        rep(i,mx) {
            double sm=0;
            pii p={0,0};
            int d=i;
            for (int j=0; j<n; ++j,d/=2) {
                pii bgn=d%2?a[j].f:a[j].s,end=d%2?a[j].s:a[j].f;
                sm+=sqrt(pow(bgn.f-p.f,2)+pow(bgn.s-p.s,2))/sp;
                p=end;
                sm+=sqrt(pow(bgn.f-p.f,2)+pow(bgn.s-p.s,2))/t;
            }
            chmin(ans,sm);
        }
    } while (next_permutation(all(a)));
    cout<<fixed<<setprecision(20);
    print(ans);

    return 0;
}
