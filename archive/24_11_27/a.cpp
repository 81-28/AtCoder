// https://atcoder.jp/contests/abc381/tasks/abc381_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    bool ok = 1;
    if (n%2==0) {
        YesNo(0);
        return 0;
    }
    rep(i,n) {
        if (i+1==(n+1)/2) {
            if (s[i] != '/'){
                ok = 0;
                break;
            }
        } else if (i+1 < (n+1)/2) {
            if (s[i] != '1') {
                ok = 0;
                break;
            }
        } else {
            if (s[i] != '2') {
                ok = 0;
                break;
            }
        }
    }
    YesNo(ok);

    return 0;
}
