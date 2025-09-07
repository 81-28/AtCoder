// https://atcoder.jp/contests/abc422/tasks/abc422_d

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

    int n,k;
    cin >> n >> k; 
    int u=0;
    vi ans(1,k);
    rep(i,n) {
        vi a;
        int x=0;
        for (int val:ans) {
            if (val%2) {
                x=1;
                a.pb(val/2);
                a.pb(val/2+1);
            } else {
                a.pb(val/2);
                a.pb(val/2);
            }
        }
        ans=a;
        u|=x;
    }
    print(u);
    print(ans);

    return 0;
}
