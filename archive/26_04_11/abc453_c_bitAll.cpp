// https://atcoder.jp/contests/abc453/tasks/abc453_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
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
    vi l(n);
    cin >> l;
    int mx=1LL<<n;
    int ans=0;
    rep(i,mx) {
        int pos=0;
        int res=0;
        rep(j,n) {
            if ((i>>j)&1) {
                if (pos<0 && pos+l[j]>=0) ++res;
                pos+=l[j];
            } else {
                if (pos>=0 && pos-l[j]<0) ++res;
                pos-=l[j];
            }
        }
        chmax(ans,res);
    }
    print(ans);

    return 0;
}
