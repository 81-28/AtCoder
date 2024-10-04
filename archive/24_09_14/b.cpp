// https://atcoder.jp/contests/abc371/tasks/abc371_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
template<typename T>
using v = vector<T>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    v<bool> d(n,false);
    rep(i,m) {
        int a;
        char b;
        cin >> a >> b;
        YesNo(!d[a-1] && b == 'M');
        if (b == 'M') d[a-1] = true;
    }

    return 0;
}
