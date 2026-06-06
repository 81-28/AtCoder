// https://atcoder.jp/contests/abc461/tasks/abc461_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b(n);
    cin >> a;
    rep(i,n) {
        int c;
        cin >> c;
        b[c-1]=i;
    }
    rep(i,n) {
        if (a[i]-1!=b[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
