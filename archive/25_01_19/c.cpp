// https://atcoder.jp/contests/abc389/tasks/abc389_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using pll=pair<ll,ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    ll base=0;
    ll n,l,k;
    ll idx = 0;
    v<pll> sn;
    ll last = 0;
    rep(i,q) {
        cin >> n;
        if (n==1) {
            cin >> l;
            sn.pb({l,last});
            last += l;
        }
        if (n==2) {
            base += sn[idx].first;
            idx++;
        }
        if (n==3) {
            cin >> k;
            print(sn[k-1+idx].second - base);
        }
    }

    return 0;
}
