// https://atcoder.jp/contests/abc256/tasks/abc256_c

#include<bits/stdc++.h>
using namespace std;

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

    vi h(3),w(3);
    cin >> h >> w;
    int ans=0;
    for (int i=1; i<h[0]; ++i) {
        for (int j=1; j<h[0]; ++j) {
            int k=h[0]-i-j;
            if (k<1) continue;
            for (int x=1; x<h[1]; ++x) {
                for (int y=1; y<h[1]; ++y) {
                    int z=h[1]-x-y;
                    if (z<1) continue;
                    int a=w[0]-i-x;
                    if (a<1) continue;
                    int b=w[1]-j-y;
                    if (b<1) continue;
                    int c=w[2]-k-z;
                    if (c<1) continue;
                    if (a+b+c==h[2]) ++ans;
                }
            }
        }
    }
    print(ans);

    return 0;
}
