// https://atcoder.jp/contests/abc460/tasks/abc460_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    cin >> a >> b;
    sort(rall(a));
    multiset<int> s(all(b));
    int ans=0;
    rep(i,n) {
        if (s.size()==0) break;
        auto it=s.upper_bound(a[i]*2);
        if (it==s.begin()) continue;
        --it;
        ++ans;
        s.erase(it);
    }
    print(ans);

    return 0;
}
