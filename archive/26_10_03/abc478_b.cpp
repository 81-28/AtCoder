// https://atcoder.jp/contests/abc478/tasks/abc478_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi w(n);
    cin >> w;
    int mx=0;
    rep(i,n)
        for (int j=i+1; j<n; ++j)
            for (int k=j+1; k<n; ++k) {
                if (i+j+k+3>m) break;
                chmax(mx,w[i]+w[j]+w[k]);
            }
    print(mx);

    return 0;
}
