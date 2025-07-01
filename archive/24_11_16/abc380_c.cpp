// https://atcoder.jp/contests/abc380/tasks/abc380_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>
using v=vector<T>;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    string s;
    cin >> n >> k >> s;
    v<string> a;
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            a.pb(substring(s,last,i));
            last = i;
        }
    }
    a.pb(substring(s,last,n));
    string tmp;
    if (s[0] == '0') {
        tmp = a[k*2-1];
        a[k*2-1] = a[k*2-2];
        a[k*2-2] = tmp;
    } else {
        tmp = a[(k-1)*2];
        a[(k-1)*2] = a[(k-1)*2-1];
        a[(k-1)*2-1] = tmp;
    }
    int an = a.size();
    rep(i,an) cout<<a[i];
    cout<<'\n';

    return 0;
}
