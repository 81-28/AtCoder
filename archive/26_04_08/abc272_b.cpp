// https://atcoder.jp/contests/abc272/tasks/abc272_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using vvb=v<vb>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvb b(n+1,vb(n+1,0));
    while (m--) {
        int k;
        cin >> k;
        vi x(k);
        cin >> x;
        rep(i,k-1)for(int j=i+1; j<k; ++j) b[x[i]][x[j]]=1;
    }
    rep1(i,n-1)for(int j=i+1; j<=n; ++j) {
        if (!b[i][j]&&!b[j][i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
