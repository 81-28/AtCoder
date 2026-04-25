// https://atcoder.jp/contests/abc455/tasks/abc455_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vi par(n+1);
    rep1(i,n) par[i]=i;
    rep1(i,q) {
        int c,p;
        cin >> c >> p;
        par[c]=p;
    }
    vi chi(n+1,0);
    rep1(i,n) {
        if (par[i]==i) continue;
        chi[par[i]]=i;
    }
    rep1(i,n) {
        if (par[i]!=i) {
            cout<<0<<' ';
            continue;
        }
        int ans=0,pos=i;
        while (pos!=0) {
            ++ans;
            pos=chi[pos];
        }
        cout<<ans<<' ';
    }
    cout<<endl;

    return 0;
}
