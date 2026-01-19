// https://atcoder.jp/contests/abc283/tasks/abc283_b

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

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int q;
    cin >> q;
    while (q--) {
        int m,k,x;
        cin >> m >> k;
        if (m==1) {
            cin >> x;
            a[--k]=x;
        } else print(a[--k]);
    }

    return 0;
}
