// https://atcoder.jp/contests/abc324/tasks/abc324_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int a;
    cin >> a;
    int b;
    rep(i,n-1) {
        cin >> b;
        if (a != b) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
