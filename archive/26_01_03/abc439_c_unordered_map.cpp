// https://atcoder.jp/contests/abc439/tasks/abc439_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a;
    for (int i=1; i*i<n; ++i) a.pb(i*i);
    // mapでは間に合わない
    unordered_map<int,int> mp;
    for (int val:a) {
        auto itl=upper_bound(all(a),val);
        auto itr=upper_bound(all(a),n-val);
        if (0>=itr-itl) break;
        for (auto it=itl; it!=itr; ++it) ++mp[*it+val];
    }
    vi ans;
    for (auto[num,cnt]:mp) {
        if (cnt==1) ans.pb(num);
    }
    sort(all(ans));
    print(ans.size());
    print(ans);

    return 0;
}
