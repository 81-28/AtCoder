// https://atcoder.jp/contests/abc482/tasks/abc482_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi x(n);
    cin >> x;
    rep(i,n) {
        int res=(x[n-1]-x[0])/2;
        if (i==0||i==n-1) {
            print(res);
            continue;
        }
        chmin(res,max((x[n-1]-x[i])/2,(x[i+1]-x[0])/2));
        chmin(res,max((x[n-1]-x[i-1])/2,(x[i]-x[0])/2));
        print(res);
    }

    return 0;
}
