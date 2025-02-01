// https://atcoder.jp/contests/abc391/tasks/abc391_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define f first
#define s second
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
using ll=long long;
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}
// #define max(...) (*max_element({__VA_ARGS__}))
// #define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,w;
    cin >> n >> w;
    vvll c(w+1);
    v<pll> p(n);
    rep(i,n) {
        cin >> p[i].f >> p[i].s;
        c[p[i].f].pb(p[i].s);
    }
    rep1(i,w) sort(all(c[i]));

    ll q;
    cin >> q;
    v<pair<pll,ll>> d(q);
    rep(i,q) {
        cin >> d[i].f.f >> d[i].s;
        d[i].f.s = i;
    }
    sort(all(d));

    ll t,a;
    pll pos;
    ll amo,amo2;
    bool ok;
    v<map<ll,ll>> m(w+1);
    auto it=c[0].begin();
    vi ans(q);
    rep(i,q) {
        t=d[i].f.f;
        a=d[i].s;
        pos=p[a-1];
        if (pos.s - t > 0) {
            ans[d[i].f.s] = 1;
            continue;
        }

        if (!m[pos.f][pos.s]) {
            it = upper_bound(all(c[pos.f]),pos.s);
            amo = distance(c[pos.f].begin(),it);
            m[pos.f][pos.s] = amo;
        } else amo=m[pos.f][pos.s];

        ok=0;
        rep1(j,w) {
            if (j != pos.f) {
                if (!m[j][t]) {
                    it = upper_bound(all(c[j]),t);
                    amo2 = distance(c[j].begin(),it);
                    m[j][t] = amo2;
                } else amo2=m[j][t];

                if (amo2 < amo) {
                    ok=1;
                    break;
                }
            }
        }
        ans[d[i].f.s] = ok;
    }
    rep(i,q) YesNo(ans[i]);

    return 0;
}
