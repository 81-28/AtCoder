// https://atcoder.jp/contests/abc438/tasks/abc438_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int ans=n;
    v<pii> c;
    int cmb=1;
    rep(i,n-1) {
        if (a[i]!=a[i+1]) {
            c.pb({a[i],cmb});
            cmb=0;
        }
        ++cmb;
    }
    c.pb({a[n-1],cmb});
    stack<pii> t;
    for (auto&[num,cnt]:c) {
        if (!t.empty()) {
            auto[nt,ct]=t.top();
            if (nt==num) {
                cnt+=ct;
                t.pop();
            }
        }
        if (cnt>=4) {
            ans-=(cnt/4)*4;
            cnt%=4;
        }
        if (cnt!=0) t.push({num,cnt});
    }
    print(ans);

    return 0;
}
