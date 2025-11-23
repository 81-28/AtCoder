// https://atcoder.jp/contests/abc290/tasks/abc290_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    sort(all(a));
    if (*a.begin()) {
        print(0);
        return 0;
    }
    uniq(a);
    int l=0,r=k+1;
    // lでOKでrでNGとなる
    while (l+1<r) {
        int m=(l+r)/2;
        auto it=lower_bound(all(a),m);
        int cnt=it-a.begin();
        if (cnt<m) r=m;
        else l=m;
    }
    print(l);

    return 0;
}
