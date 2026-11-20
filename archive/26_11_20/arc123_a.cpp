// https://atcoder.jp/contests/arc123/tasks/arc123_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(3);
    cin >> a;
    int sm=a[0]+a[2];
    int ave=(sm+1)/2;
    if (a[1]<=ave) print(ave-a[1]+(sm&1));
    else print(a[1]*2-sm);

    return 0;
}
