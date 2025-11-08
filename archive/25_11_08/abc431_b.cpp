// https://atcoder.jp/contests/abc431/tasks/abc431_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,n;
    cin >> x >> n;
    vi w(n);
    int q;
    cin >> w >> q;
    v<bool> b(n,0);
    while (q--) {
        int p;
        cin >> p;
        --p;
        if (!b[p]) {
            b[p]=1;
            x+=w[p];
        } else {
            b[p]=0;
            x-=w[p];
        }
        print(x);
    }

    return 0;
}
