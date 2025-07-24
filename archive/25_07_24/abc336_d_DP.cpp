// https://atcoder.jp/contests/abc336/tasks/abc336_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

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
    // 左右から登る最大高さ
    vi l(n),r(n);
    rep(i,n) {
        if (i==0) l[i]=min(1,a[i]);
        else l[i]=min(l[i-1]+1,a[i]);
    }
    for (int i=n-1; i>=0; --i) {
        if (i==n-1)  r[i]=min(1,a[i]);
        else r[i]=min(r[i+1]+1,a[i]);
    }
    int ans=1;
    rep(i,n) chmax(ans,min(l[i],r[i]));
    print(ans);

    return 0;
}
