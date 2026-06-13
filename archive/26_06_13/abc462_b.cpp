// https://atcoder.jp/contests/abc462/tasks/abc462_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(n);
    rep(i,n) {
        int k;
        cin >> k;
        rep(j,k) {
            int b;
            cin >> b;
            a[--b].pb(i+1);
        }
    }
    for (vi vec:a) {
        cout<<vec.size()<<' ';
        print(vec);
    }

    return 0;
}
