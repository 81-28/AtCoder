// https://atcoder.jp/contests/abc484/tasks/abc484_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int k;
    cin >> k;
    vi a(k);
    cin >> a;
    sort(all(a));
    if (a.back()!=9) {
        print(-1);
        return 0;
    }
    print(a[0]);

    return 0;
}
