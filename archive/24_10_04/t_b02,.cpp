// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ca

#include <bits/stdc++.h>
using namespace std;

#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main() {
    fastio();

    int a,b;
    cin >> a >> b;
    bool ok = false;
    for (int i = a; i <= b; i++) {
        if (100%i == 0) {
            ok = true;
            break;
        }
    }
    YesNo(ok);

    return 0;
}
