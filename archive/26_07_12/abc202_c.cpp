// https://atcoder.jp/contests/abc202/tasks/abc202_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vi a(n),b(n),c(n);
    cin >> a >> b >> c;
    vi cnt(n+1,0);
    for (int val:c) ++cnt[b[val-1]];
    int ans=0;
    for (int val:a) ans+=cnt[val];
    print(ans);

    return 0;
}
