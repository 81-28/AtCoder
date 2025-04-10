// https://atcoder.jp/contests/abc308/tasks/abc308_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
using ld=long double;
template<typename T>
using v=vector<T>;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pair<ld,int>> p(n);
    int a,b;
    rep(i,n) {
        cin >> a >> b;
        p[i]={a==0?DBL_MAX:b/(ld)a,i+1};
    }
    sort(all(p));
    for (auto val:p) {
        cout<<val.second<<' ';
    }
    cout<<'\n';

    return 0;
}
