// https://atcoder.jp/contests/abc302/tasks/abc302_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


int m;
bool almEqu(const string& s,const string& t) {
    int dif=0;
    rep(i,m) dif+=s[i]!=t[i];
    return dif<2;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    sort(all(s));
    do {
        bool ok=1;
        rep(i,n-1) {
            if (!almEqu(s[i],s[i+1])) {
                ok=0;
                break;
            }
        }
        if (ok) {
            YesNo(1);
            return 0;
        }
    } while (next_permutation(all(s)));
    YesNo(0);

    return 0;
}
