// https://atcoder.jp/contests/abc420/tasks/abc420_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    vi a(n,0);
    rep(i,m) {
        vi cnt(2,0);
        rep(j,n) {
            bool b=s[j][i]-'0';
            ++cnt[b];
        }
        bool d=(cnt[1]>cnt[0]);
        rep(j,n) {
            bool b=s[j][i]-'0';
            if (b!=d) ++a[j];
        }
    }
    int mx=max(a);
    rep(i,n) {
        if (a[i]==mx) cout<<i+1<<' ';
    }
    cout<<endl;

    return 0;
}
