// https://atcoder.jp/contests/abc416/tasks/abc416_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vi a(n),b(n);
        cin >> a >> b;
        multiset<int> s;
        rep(i,n) s.insert(a[i]);
        int ans=sum(a)+sum(b);
        rep(i,n) {
            int d=m-b[i];
            auto it=s.lower_bound(d);
            if (it!=s.end()) {
                ans-=m;
                s.erase(it);
            }
        }
        print(ans);
    }

    return 0;
}
