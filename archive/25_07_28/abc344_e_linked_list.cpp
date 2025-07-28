// https://atcoder.jp/contests/abc344/tasks/abc344_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int head;
    // m[i]:{前の数,後の数}
    unordered_map<int,pii> m;
    rep(i,n) {
        if (i==0) {
            head=a[i];
            m[a[i]]={0,a[i+1]};
        } else if (i==n-1) {
            m[a[i]]={a[i-1],0};
        } else {
            m[a[i]]={a[i-1],a[i+1]};
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int b,x,y;
        cin >> b;
        if (b==1) {
            cin >> x >> y;
            int nxt=m[x].s;
            m[y]={x,nxt};
            m[x].s=y;
            if (nxt!=0) m[nxt].f=y;
        }
        if (b==2) {
            cin >> x;
            auto[pre,nxt]=m[x];
            if (pre!=0) m[pre].s=nxt;
            else head=nxt;
            if (nxt!=0) m[nxt].f=pre;
        }
    }
    while (head!=0) {
        cout<<head<<' ';
        head=m[head].s;
    }
    cout<<endl;

    return 0;
}
