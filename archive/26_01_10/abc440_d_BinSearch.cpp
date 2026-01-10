// https://atcoder.jp/contests/abc440/tasks/abc440_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
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
    while (q--) {
        int x,y;
        cin >> x >> y;
        auto it=lower_bound(all(a),x);
        int i=it-a.begin();
        // lとrの間にある
        int l=i-1,r=n;
        while (l+1<r) {
            int m=(l+r)/2;
            int cnt=a[m]-x-(m-i-1);
            if (cnt<=y) l=m;
            else r=m;
        }
        print(y+x+l-i);
    }

    return 0;
}
