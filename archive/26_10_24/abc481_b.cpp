// https://atcoder.jp/contests/abc481/tasks/abc481_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    int ans=0;
    rep(i,n) {
        if (a[i]==k) ++ans;
        if (!i) continue;
        int b=a[i-1],c=a[i];
        if (b>c) {
            int tmp=b;
            b=c;
            c=tmp;
        }
        if (b<k && k<c) ++ans;
    }
    print(ans);

    return 0;
}
