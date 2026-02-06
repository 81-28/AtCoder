// https://atcoder.jp/contests/abc276/tasks/abc276_d

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
    int g=gcd(a[0],a[1]);
    for (int i=2; i<n; ++i) g=gcd(g,a[i]);
    int ans=0;
    for (int val:a) {
        val/=g;
        while (val%2==0) {
            val/=2;
            ++ans;
        }
        while (val%3==0) {
            val/=3;
            ++ans;
        }
        if (val!=1) {
            print(-1);
            return 0;
        }
    }
    print(ans);

    return 0;
}
