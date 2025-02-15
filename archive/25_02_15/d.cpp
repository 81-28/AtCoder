// https://atcoder.jp/contests/abc393/tasks/abc393_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    string s;
    cin >> n >> s;
    ll ans=0;
    ll l=0,r=n-1;
    ll c=0;
    while(!(s[l]-'0'))l++;
    while(!(s[r]-'0'))r--;
    rep(i,n) if (s[i]-'0')c++;
    if (c%2) {
        c = (c+1)/2;
        ll cc=0;
        ll sc=0;
        for (ll i=l; i<=r; i++) {
            if (s[i]-'0') {
                cc++;
                if (cc==c) {
                    sc=i;
                    break;
                }
            }
        }

        for (ll i=l; i<sc; i++) {
            if (!(s[i]-'0')) {
                ans+=i-l;
                l++;
            }
        }
        for (ll i=r; i>sc; i--) {
            if (!(s[i]-'0')) {
                ans+=r-i;
                r--;
            }
        }
    } else {
        c /=2;
        ll cc=0;
        ll cl=0,cr=0;
        for (ll i=l; i<=r; i++) {
            if (s[i]-'0') {
                cc++;
                if (cc==c) {
                    cl=i;
                    break;
                }
            }
        }
        for (ll i=cl+1; i<=r; i++) {
            if (s[i]-'0') {
                cr=i;
                break;
            }
        }

        for (ll i=l; i<cl; i++) {
            if (!(s[i]-'0')) {
                ans+=i-l;
                l++;
            }
        }
        for (ll i=r; i>cr; i--) {
            if (!(s[i]-'0')) {
                ans+=r-i;
                r--;
            }
        }
        ans+=(cr-cl-1)*c;
    }
    print(ans);

    return 0;
}
