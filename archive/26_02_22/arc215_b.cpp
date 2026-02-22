// https://atcoder.jp/contests/arc215/tasks/arc215_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using vvb=v<vb>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n*2);
        cin >> a;
        vvb b(2,vb(n,0));
        bool d=0;
        vi ans;
        rep(i,n*2) {
            --a[i];
            if (b[d][a[i]]) {
                ans.pb(i);
                d^=1;
            }
            b[d][a[i]]=1;
        }
        print(ans.size());
        print(ans);
    }

    return 0;
}
