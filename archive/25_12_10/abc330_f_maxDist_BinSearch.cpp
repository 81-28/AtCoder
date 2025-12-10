// https://atcoder.jp/contests/abc330/tasks/abc330_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    sort(all(x)),sort(all(y));
    int xmx=*x.rbegin()-*x.begin();
    int ymx=*y.rbegin()-*y.begin();

    // {idx,値,個数}
    // 天井
    int ci,ca=*x.rbegin(),cn;
    auto itc=lower_bound(all(x),ca);
    ci=itc-x.begin();
    cn=n-ci;
    // 床
    int fi,fa=*x.begin(),fn;
    auto itf=upper_bound(all(x),fa);
    --itf;
    fi=itf-x.begin();
    fn=fi+1;

    int cnt=0;
    // {一番離れている距離,操作回数,次の点に移るのに必要な動く点の数}
    v<tuple<int,int,int>> xx(1,{xmx,cnt,min(cn,fn)});
    while (ca>fa) {
        if (cn<fn) {
            --ci;
            cnt+=cn*(ca-x[ci]);
            ca=x[ci];
            itc=lower_bound(all(x),ca);
            ci=itc-x.begin();
            cn=n-ci;
        } else {
            ++fi;
            cnt+=fn*(x[fi]-fa);
            fa=x[fi];
            itf=upper_bound(all(x),fa);
            --itf;
            fi=itf-x.begin();
            fn=fi+1;
        }
        xx.pb({ca-fa,cnt,min(cn,fn)});
    }
    sort(all(xx));

    ca=*y.rbegin();
    itc=lower_bound(all(y),ca);
    ci=itc-y.begin();
    cn=n-ci;
    fa=*y.begin();
    itf=upper_bound(all(y),fa);
    --itf;
    fi=itf-y.begin();
    fn=fi+1;

    cnt=0;
    v<tuple<int,int,int>> yy(1,{ymx,cnt,min(cn,fn)});
    while (ca>fa) {
        if (cn<fn) {
            --ci;
            cnt+=cn*(ca-y[ci]);
            ca=y[ci];
            itc=lower_bound(all(y),ca);
            ci=itc-y.begin();
            cn=n-ci;
        } else {
            ++fi;
            cnt+=fn*(y[fi]-fa);
            fa=y[fi];
            itf=upper_bound(all(y),fa);
            --itf;
            fi=itf-y.begin();
            fn=fi+1;
        }
        yy.pb({ca-fa,cnt,min(cn,fn)});
    }
    sort(all(yy));

    int mx=max(xmx,ymx);
    // (l:NG,r:OK]
    int l=-1,r=mx;
    while (l+1<r) {
        int m=(l+r)/2;
        auto itx=upper_bound(all(xx),make_tuple(m,LLONG_MAX,LLONG_MAX));
        int cntx = itx==xx.end() ? 0 : get<1>(*itx)+get<2>(*itx)*(get<0>(*itx)-m);
        auto ity=upper_bound(all(yy),make_tuple(m,LLONG_MAX,LLONG_MAX));
        int cnty = ity==yy.end() ? 0 : get<1>(*ity)+get<2>(*ity)*(get<0>(*ity)-m);
        if (cntx+cnty<=k) r=m;
        else l=m;
    }
    print(r);

    return 0;
}
