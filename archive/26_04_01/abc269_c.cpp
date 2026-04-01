// https://atcoder.jp/contests/abc269/tasks/abc269_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(1,0);
    for (int i=0; n; ++i,n/=2) {
        if (!(n&1)) continue;
        vi res;
        for (int val:a) {
            res.pb(val);
            res.pb(val|(1LL<<i));
        }
        a=res;
    }
    sort(all(a));
    for (int val:a) print(val);

    return 0;
}
