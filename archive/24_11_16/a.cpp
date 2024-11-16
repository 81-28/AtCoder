// https://atcoder.jp/contests/abc380/tasks/abc380_a

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string n;
    cin >> n;
    sort(all(n));
    YesNo(n=="122333");

    return 0;
}
