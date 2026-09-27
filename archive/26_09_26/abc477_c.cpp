// https://atcoder.jp/contests/abc477/tasks/abc477_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    string s,t;
    cin >> q >> s >> t;
    int n=s.size(),m=t.size();
    vi a;
    rep(i,n+1-m) {
        bool ok=1;
        rep(j,m) {
            if (s[i+j]!=t[j]) {
                ok=0;
                break;
            }
        }
        if (ok) a.pb(i);
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        auto it=lower_bound(all(a),--l);
        YesNo(it!=a.end() && *it+m <= r);
    }

    return 0;
}
