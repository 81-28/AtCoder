// https://atcoder.jp/contests/abc321/tasks/abc321_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int m=-1;
    for (; n>0; n/=10) {
        if(n%10 <= m) {
            YesNo(0);
            return 0;
        }
        m=n%10;
    }
    YesNo(1);

    return 0;
}
