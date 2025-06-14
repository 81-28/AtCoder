// https://atcoder.jp/contests/abc410/tasks/abc410_a

#include<bits/stdc++.h>
using namespace std;
#define int ll

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int k;
    vi a(n);
    cin >> a >> k;
    int ans=0;
    rep(i,n) ans+=k<=a[i];
    print(ans);

    return 0;
}
