// https://atcoder.jp/contests/ACcareer27/tasks/ACcareer27_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(n,vi(n));
    cin >> a;
    set<int> s;
    vi c(n,0),r(n,0);
    rep(i,n)rep(j,n) {
        if (s.find(a[i][j])!=s.end()) {
            YesNo(0);
            return 0;
        }
        r[i]+=a[i][j];
        c[j]+=a[i][j];
        s.insert(a[i][j]);
    }
    s.clear();
    rep(i,n) {
        if (s.find(c[i])!=s.end()) {
            YesNo(0);
            return 0;
        }
        s.insert(c[i]);
        if (s.find(r[i])!=s.end()) {
            YesNo(0);
            return 0;
        }
        s.insert(r[i]);
    }
    YesNo(1);

    return 0;
}
