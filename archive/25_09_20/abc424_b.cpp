// https://atcoder.jp/contests/abc424/tasks/abc424_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    v<v<bool>> b(n,v<bool>(m,0));
    vi ans;
    rep(i,k) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        b[x][y]=1;
        bool ok=1;
        rep(j,m) {
            if (!b[x][j]) {
                ok=0;
                break;
            }
        }
        if (ok) ans.pb(x+1);
    }
    print(ans);

    return 0;
}
