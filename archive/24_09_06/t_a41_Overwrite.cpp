// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ao

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


int main() {
    fastio();

    int n;
    string s;
    cin >> n >> s;
    bool ok = false;
    rep(i,n-2) {
        string sub = substring(s,i,i+3);
        if (sub == "RRR" || sub == "BBB") {
            ok = true;
            break;
        }
    }
    YesNo(ok);

    return 0;
}
