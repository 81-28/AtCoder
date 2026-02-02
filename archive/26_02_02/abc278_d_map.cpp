// https://atcoder.jp/contests/abc278/tasks/abc278_d

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
    cin >> n;
    vi a(n);
    cin >> a >> q;
    int base=0;
    map<int,int> mp;
    rep(i,n) mp[i+1]=a[i];
    while (q--) {
        int m,i,x;
        cin >> m;
        if (m==1) {
            cin >> x;
            mp.clear();
            base=x;
        } else if (m==2) {
            cin >> i >> x;
            mp[i]+=x;
        } else {
            cin >> i;
            print(base+mp[i]);
        }
    }

    return 0;
}
