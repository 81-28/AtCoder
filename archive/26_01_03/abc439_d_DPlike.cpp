// https://atcoder.jp/contests/abc439/tasks/abc439_d

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

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int ans=0;
    map<int,int> m;
    rep(i,n) {
        ++m[a[i]];
        if (a[i]%5) continue;
        int thr=a[i]/5*3;
        int sev=a[i]/5*7;
        ans+=m[thr]*m[sev];
    }
    m.clear();
    for (int i=n-1; i>=0; --i) {
        ++m[a[i]];
        if (a[i]%5) continue;
        int thr=a[i]/5*3;
        int sev=a[i]/5*7;
        ans+=m[thr]*m[sev];
    }
    print(ans);

    return 0;
}
