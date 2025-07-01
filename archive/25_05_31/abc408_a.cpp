// https://atcoder.jp/contests/abc408/tasks/abc408_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,s;
    cin >> n >> s;
    vi t(n);
    cin >> t;
    int l=s;
    rep(i,n) {
        if (l>=t[i]) {
            l=t[i]+s;
        } else {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
