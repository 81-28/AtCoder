// https://atcoder.jp/contests/abc256/tasks/abc256_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi c(5,0);
    while (n--) {
        int a;
        cin >> a;
        ++c[0];
        for (int i=3; i>=0; --i) {
            c[min(4,i+a)]+=c[i];
            c[i]=0;
        }
    }
    print(c[4]);

    return 0;
}
