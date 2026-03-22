// https://atcoder.jp/contests/ACcareer27/tasks/ACcareer27_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    n-=k;
    vi x(m);
    vi r(m);
    rep(i,m) {
        cin >> x[i];
        x[i]-=k;
        r[i]=n-x[i];
    }
    v<string> ans(n,string(m,'x'));
    rep(i,n) {
        bool b=1;
        rep(j,m) {
            if (b&&r[j]) {
                b=0;
                --r[j];
                continue;
            }
            if (x[j]>0) {
                --x[j];
                ans[i][j]='o';
            }
        }
    }
    rep(i,k) print(string(m,'o'));
    rep(i,n) print(ans[i]);

    return 0;
}
