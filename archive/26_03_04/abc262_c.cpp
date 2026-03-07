// https://atcoder.jp/contests/abc262/tasks/abc262_c

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
    int match=0;
    rep(i,n) {
        if (a[i]==i+1) ans+=match++;
        else {
            if (a[i]>i+1) continue;
            if (a[a[i]-1]==i+1) ++ans;
        }
    }
    print(ans);

    return 0;
}
