// https://atcoder.jp/contests/abc289/tasks/abc289_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n,m;
vvi a;
int dfs(const int& l,v<bool> b) {
    if (l==m) {
        bool ok=1;
        rep1(i,n) {
            if (!b[i]) {
                ok=0;
                break;
            }
        }
        return ok;
    }
    int res=dfs(l+1,b);
    for (int val:a[l]) b[val]=1;
    return res+dfs(l+1,b);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    a=vvi(m);
    rep(i,m) {
        int c;
        cin >> c;
        a[i]=vi(c);
        cin >> a[i];
    }
    print(dfs(0,v<bool>(n+1,0)));

    return 0;
}
