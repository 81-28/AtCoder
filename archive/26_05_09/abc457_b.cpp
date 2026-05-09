// https://atcoder.jp/contests/abc457/tasks/abc457_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(n);
    rep(i,n) {
        int l;
        cin >> l;
        a[i]=vi(l);
        cin >> a[i];
    }
    int x,y;
    cin >> x >> y;
    print(a[x-1][y-1]);

    return 0;
}
