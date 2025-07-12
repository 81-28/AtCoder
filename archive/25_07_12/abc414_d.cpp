// https://atcoder.jp/contests/abc414/tasks/abc414_d

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
    vi x(n);
    cin >> x;
    sort(all(x));
    vi dif(n-1);
    rep(i,n-1) dif[i]=x[i+1]-x[i];
    sort(rall(dif));
    int ans=*x.rbegin()-*x.begin();
    rep(i,m-1) ans-=dif[i];
    print(ans);

    return 0;
}
