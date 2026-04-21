// https://atcoder.jp/contests/abc254/tasks/abc254_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a;
    for (int i=1; i*i<=n; ++i) a.pb(i*i);
    int l=a.size();
    int ans=0;
    rep1(i,n) {
        if (find(all(a),i)!=a.end()) {
            ans+=l;
        } else {
            int m=i;
            for (int j=1; j<l; ++j) {
                if (a[j]>m) break;
                if (m%a[j]==0) m/=a[j--];
            }
            auto it=upper_bound(all(a),n/m);
            ans+=it-a.begin();
        }
    }
    print(ans);

    return 0;
}
