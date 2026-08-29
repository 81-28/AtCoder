// https://atcoder.jp/contests/abc473/tasks/abc473_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    map<int,int> m;
    m[0]=0;
    int mx=0;
    int sm=0;
    int dp=0;
    rep(i,n) {
        sm+=a[i];
        sm%=k;
        int res=mx;
        auto it=m.find(sm);
        if (it!=m.end()) {
            chmax(res,it->second+1);
            chmax(it->second,res);
        } else {
            m[sm]=res;
        }
        chmax(mx,res);
        dp=res;
    }
    print(dp);

    return 0;
}
