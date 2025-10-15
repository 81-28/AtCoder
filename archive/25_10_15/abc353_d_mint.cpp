// https://atcoder.jp/contests/abc353/tasks/abc353_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;

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
    mint ans=0;
    mint sm=0;
    for (int i=n-1; i>=0; --i) {
        ans+=a[i]*(i+sm);
        int e=to_string(a[i]).size();
        sm+=mint(10).pow(e);
    }
    print(ans.val());

    return 0;
}
