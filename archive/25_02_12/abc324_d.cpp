// https://atcoder.jp/contests/abc324/tasks/abc324_d

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
using ll=long long;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    string s;
    cin >> n >> s;
    sort(all(s));
    ll q = sqrt(pow(10,n)-1);
    string t;
    ll m;
    ll ans = 0;
    for(ll i=0; i<=q; i++) {
        t = string(n,'0');
        m = i*i;
        for(ll j=n-1; j>=0 && m>0; j--) {
            t[j] += m%10;
            m/=10;
        }
        sort(all(t));
        if(s==t)ans++;
    }
    print(ans);

    return 0;
}
