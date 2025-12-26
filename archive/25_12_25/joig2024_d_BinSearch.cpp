// https://atcoder.jp/contests/joig2024-open/tasks/joig2024_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi ten(11,1);
    rep1(i,10) ten[i]=ten[i-1]*10;

    int n;
    cin >> n;
    vi a(n),b=a;
    cin >> a >> b;
    sort(all(a)),sort(all(b));
    int ans=0;
    for (int ai:a) {
        // ai+bがd桁となる個数を求める
        rep1(d,10) {
            auto itl=lower_bound(all(b),ten[d-1]-ai);
            auto itr=lower_bound(all(b),ten[d]-ai);
            ans+=d*(itr-itl);
        }
    }
    print(ans);

    return 0;
}
