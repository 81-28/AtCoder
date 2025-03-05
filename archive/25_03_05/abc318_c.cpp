// https://atcoder.jp/contests/abc318/tasks/abc318_c

#include<bits/stdc++.h>
using namespace std;

#define rall(v) v.rbegin(),v.rend()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,d,p;
    cin >> n >> d >> p;
    vll f(n);
    cin >> f;
    sort(rall(f));
    ll h=0,t=0;
    ll s;
    ll ans=0;
    while (h!=n) {
        t=min(h+d,n);
        s=accumulate(f.begin()+h,f.begin()+t,0LL);
        if (p<s) {
            ans+=p;
            h=t;
        } else break;
    }
    ans+=accumulate(f.begin()+h,f.begin()+n,0LL);
    print(ans);

    return 0;
}
