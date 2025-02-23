// https://atcoder.jp/contests/abc321/tasks/abc321_c

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll k;
    cin >> k;
    vll r;
    r.pb(0);
    for(ll a=1;a<10;a++) r.pb(a);
    ll n;
    for(ll a=1;a<10;a++)for(ll b=0;b<a;b++) {
        n=a,n=n*10+b;
        r.pb(n);
    }
    for(ll a=2;a<10;a++)for(ll b=1;b<a;b++)for(ll c=0;c<b;c++) {
        n=a,n=n*10+b,n=n*10+c;
        r.pb(n);
    }
    for(ll a=3;a<10;a++)for(ll b=2;b<a;b++)for(ll c=1;c<b;c++)for(ll d=0;d<c;d++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d;
        r.pb(n);
    }
    for(ll a=4;a<10;a++)for(ll b=3;b<a;b++)for(ll c=2;c<b;c++)for(ll d=1;d<c;d++)for(ll e=0;e<d;e++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d,n=n*10+e;
        r.pb(n);
    }
    for(ll a=5;a<10;a++)for(ll b=4;b<a;b++)for(ll c=3;c<b;c++)for(ll d=2;d<c;d++)for(ll e=1;e<d;e++)for(ll f=0;f<e;f++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d,n=n*10+e,n=n*10+f;
        r.pb(n);
    }
    for(ll a=6;a<10;a++)for(ll b=5;b<a;b++)for(ll c=4;c<b;c++)for(ll d=3;d<c;d++)for(ll e=2;e<d;e++)for(ll f=1;f<e;f++)for(ll g=0;g<f;g++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d,n=n*10+e,n=n*10+f,n=n*10+g;
        r.pb(n);
    }
    for(ll a=7;a<10;a++)for(ll b=6;b<a;b++)for(ll c=5;c<b;c++)for(ll d=4;d<c;d++)for(ll e=3;e<d;e++)for(ll f=2;f<e;f++)for(ll g=1;g<f;g++)for(ll h=0;h<g;h++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d,n=n*10+e,n=n*10+f,n=n*10+g,n=n*10+h;
        r.pb(n);
    }
    for(ll a=8;a<10;a++)for(ll b=7;b<a;b++)for(ll c=6;c<b;c++)for(ll d=5;d<c;d++)for(ll e=4;e<d;e++)for(ll f=3;f<e;f++)for(ll g=2;g<f;g++)for(ll h=1;h<g;h++)for(ll i=0;i<h;i++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d,n=n*10+e,n=n*10+f,n=n*10+g,n=n*10+h,n=n*10+i;
        r.pb(n);
    }
    for(ll a=9;a<10;a++)for(ll b=8;b<a;b++)for(ll c=7;c<b;c++)for(ll d=6;d<c;d++)for(ll e=5;e<d;e++)for(ll f=4;f<e;f++)for(ll g=3;g<f;g++)for(ll h=2;h<g;h++)for(ll i=1;i<h;i++)for(ll j=0;j<i;j++) {
        n=a,n=n*10+b,n=n*10+c,n=n*10+d,n=n*10+e,n=n*10+f,n=n*10+g,n=n*10+h,n=n*10+i,n=n*10+j;
        r.pb(n);
    }
    print(r[k]);

    return 0;
}
