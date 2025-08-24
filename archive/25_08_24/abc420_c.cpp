// https://atcoder.jp/contests/abc420/tasks/abc420_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n),b(n);
    cin >> a >> b;
    int ans=0;
    rep(i,n) ans+=min(a[i],b[i]);
    while (q--) {
        char c;
        int x,y;
        cin >> c >> x >> y;
        --x;
        ans-=min(a[x],b[x]);
        if (c=='A') a[x]=y;
        if (c=='B') b[x]=y;
        ans+=min(a[x],b[x]);
        print(ans);
    }

    return 0;
}
