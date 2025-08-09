// https://atcoder.jp/contests/abc418/tasks/abc418_c

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

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    sort(all(a));
    vi s(n+1,0);
    rep1(i,n) s[i]=s[i-1]+a[i-1];
    while (q--) {
        int b;
        cin >> b;
        if (b>*a.rbegin()) {
            print(-1);
            continue;
        }
        auto it=lower_bound(all(a),b);
        int i=it-a.begin()-1;
        print(s[i+1]+(n-i-1)*(b-1)+1);
    }

    return 0;
}
