// https://atcoder.jp/contests/abc344/tasks/abc344_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,l,q;
    cin >> n;
    vi a(n);
    cin >> a >> m;
    vi b(m);
    cin >> b >> l;
    vi c(l);
    cin >> c >> q;
    unordered_set<int> s;
    rep(i,n)rep(j,m)rep(k,l) {
        s.insert(a[i]+b[j]+c[k]);
    }
    int x;
    rep(i,q) {
        cin >> x;
        YesNo(s.find(x)!=s.end());
    }

    return 0;
}
