// https://atcoder.jp/contests/abc379/tasks/abc379_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
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

    int q;
    cin >> q;
    map<ll,ll> m;
    int n;
    ll t,h;
    ll now = 0;
    ll ans;
    vll e;
    rep(i,q) {
        cin >> n;
        if (n == 1) {
            m[now]++;
        }
        if (n == 2) {
            cin >> t;
            now+=t;
        }
        if (n == 3) {
            ans = 0;
            cin >> h;
            e = vll(0);
            for (auto &pair : m) {
                if (pair.first<=now-h) {
                    ans+=pair.second;
                    e.pb(pair.first);
                } else break;
            }
            for (ll val : e) m.erase(val);
            print(ans);
        }
    }

    return 0;
}
