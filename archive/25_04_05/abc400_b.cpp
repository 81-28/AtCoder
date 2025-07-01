// https://atcoder.jp/contests/abc400/tasks/abc400_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll inf=1e9;
    ll n,m;
    cin >> n >> m;
    ll ans=0;
    rep(i,m+1) {
        if (pow(inf,1/(double)i)<n) {
            print("inf");
            return 0;
        }
        ans+=pow(n,i);
        if (ans>inf) {
            print("inf");
            return 0;
        }
    }
    print(ans);

    return 0;
}
