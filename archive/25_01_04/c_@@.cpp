// https://atcoder.jp/contests/abc387/tasks/abc387_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
// #define f first
// #define s second
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
using ll=long long;
using ull=unsigned long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// using mint=modint1000000007;
// using mint=modint998244353;

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


ll ans=0;

void checkL(ll l, ll ld, ll ln) {
    // for (ll i=l; i<ld*ln; i++) {
    //     string s = to_string(i);
    //     int d=(s[0]-'0');
    //     bool ok=1;
    //     if((s[1]-'0') >= d) return;

    //     for (int j=1; j < (int)s.size(); j++) {
    //         if ((s[j]-'0') >= d) {
    //             ok=0;
    //             break;
    //         }
    //     }
    //     ans+=ok;
    // }
    string s=to_string(l);
    ll lld = s[0]-'0';
    if ((s[1]-'0') >= lld) return;

    lld *= 10;
    lld += (s[1]-'0');
    ll lln = log10(l)-1;
    lln = pow(10,lln);
    if (ld==1) {
        ld*=10;
        ln/=10;
    }
    ll lll=11*(ld-1)*(ln/10);
    while(lld*lln < lll) {
        ll d=log10(lln);
        ans+=pow(lld,d);

        if (lld==9) {
            lld=1;
            lln*=10;
        } else lld++;
    }
}
void checkR(ll r, ll rn) {
    // for (ll i=rd*rn; i<=r; i++) {
    //     string s = to_string(i);
    //     int d=(s[0]-'0');
    //     bool ok=1;
    //     if((s[1]-'0') >= d) return;

    //     for (int j=1; j < (int)s.size(); j++) {
    //         if ((s[j]-'0') >= d) {
    //             ok=0;
    //             break;
    //         }
    //     }
    //     ans+=ok;
    // }
    string s=to_string(r);
    ll rrd = s[0]-'0';
    ll rrn = log10(rn)-1;
    for (int i=1; i<(int)s.size(); i++) {
        if (s[0] > s[i]) {
            ans += (s[i]-'0')*pow(rrd,rrn);
            if ((s[i]-'0') == 0 && i == (int)s.size()-1)ans++;
        } else {
            ans += pow(rrd,rrn+1);
            return;
        }
        rrn--;
    }
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll l,r;
    ll ld=0,ln=1;
    ll rd=0,rn=1;
    cin >> l >> r;
    for (ll i=l-1; i>0; i/=10) {
        ld=i;
        ln*=10;
    }
    ln/=10;
    if (ld==9) {
        ld=1;
        ln*=10;
    } else {
        ld++;
    }

    for (ll i=r; i>0; i/=10) {
        rd=i;
        rn*=10;
    }
    rn/=10;

    checkL(l,ld,ln);
    // print(ans);
    checkR(r,rn);
    // print(ans);

    ll rr=rd*rn;
    while(ld*ln < rr) {
        ll d=log10(ln);
        ans+=pow(ld,d);

        if (ld==9) {
            ld=1;
            ln*=10;
        } else ld++;
    }
    print(ans);

    return 0;
}
