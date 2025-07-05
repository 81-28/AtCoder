// https://atcoder.jp/contests/abc413/tasks/abc413_d

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
#define rall(v) v.rbegin(),v.rend()
#define YesNo(x) puts(x?"Yes":"No")

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        cin >> a;
        vi po,ne;
        rep(i,n) {
            if (a[i]>0) po.pb(a[i]);
            else ne.pb(a[i]);
        }
        int ps=po.size();
        int ns=ne.size();
        if (ps==n || ns==n) {
            sort(all(a));
            bool ok=1;
            for (int i=1; i<n-1; ++i) {
                if (a[0]*a[i+1]!=a[1]*a[i]) {
                    ok=0;
                    break;
                }
            }
            YesNo(ok);
        } else {
            if (abs(ps-ns)>1) {
                YesNo(0);
            } else {
                sort(all(po));
                sort(rall(ne));
                a=vi();
                if (ps>ns) {
                    rep(i,ns) {
                        a.pb(po[i]);
                        a.pb(ne[i]);
                    }
                    a.pb(*po.rbegin());
                } else if (ps<ns) {
                    rep(i,ps) {
                        a.pb(ne[i]);
                        a.pb(po[i]);
                    }
                    a.pb(*ne.rbegin());
                } else {
                    if (po[0]<-ne[0]) {
                        rep(i,ns) {
                            a.pb(po[i]);
                            a.pb(ne[i]);
                        }
                    } else {
                        rep(i,ns) {
                            a.pb(ne[i]);
                            a.pb(po[i]);
                        }
                    }
                }
                bool ok=1;
                for (int i=1; i<n-1; ++i) {
                    if (a[0]*a[i+1]!=a[1]*a[i]) {
                        ok=0;
                        break;
                    }
                }
                YesNo(ok);
            }
        }
    }

    return 0;
}
