// https://atcoder.jp/contests/abc160/tasks/abc160_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vi p(a),q(b),r(c);
    cin >> p >> q >> r;
    sort(rall(p)),sort(rall(q));
    priority_queue<int,vi,greater<>> qu;
    priority_queue<int> qr;
    rep(i,c) qr.push(r[i]);
    int ans=0;
    rep(i,x) {
        qu.push(p[i]);
        ans+=p[i];
    }
    rep(i,y) {
        qu.push(q[i]);
        ans+=q[i];
    }
    while (!qr.empty()) {
        int mx=qr.top();
        int mi=qu.top();
        if (mi>=mx) break;
        ans+=mx-mi;
        qr.pop();
        qu.pop();
        qu.push(mx);
    }
    print(ans);

    return 0;
}
