// https://atcoder.jp/contests/abc379/tasks/abc379_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // sm[i]: Σ(j=0~i){s[j]*(j+1)}
    vi sm(n);
    sm[0]=s[0]-'0';
    for (int i=1; i<n; ++i) sm[i]=sm[i-1]+(s[i]-'0')*(i+1);
    vi a;
    int c=0;
    for (int i=n-1; i>=0; --i) {
        int d=sm[i]+c;
        a.pb(d%10);
        c=d/10;
    }
    for (; c; c/=10) a.pb(c%10);
    for (int i=a.size()-1; i>=0; --i) cout<<a[i];
    cout<<endl;

    return 0;
}
