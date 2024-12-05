// https://atcoder.jp/contests/abc346/tasks/abc346_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,k,a;
    cin >> n >> k;
    ll ans = k*(k+1)/2;
    unordered_map<ll,bool> done;
    rep(i,n) {
        cin >> a;
        if (!done[a] && a<=k) {
            ans -= a;
            done[a]=1;
        }
    }
    print(ans);

    return 0;
}
