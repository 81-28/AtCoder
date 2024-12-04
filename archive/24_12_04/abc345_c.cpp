// https://atcoder.jp/contests/abc345/tasks/abc345_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    ll n = s.size();
    vll c(26,0);
    bool same=0;
    rep(i,n) c[s[i]-'a']++;
    ll ans = n*n;
    rep(i,26) {
        ans -= c[i]*c[i];
        if (c[i]>1) same=1;
    }
    ans/=2;
    ans+=same;
    print(ans);

    return 0;
}
