// https://atcoder.jp/contests/abc312/tasks/abc312_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    int l=1,r=*b.rbegin()+1;
    while (l<r) {
        int mid=(l+r)/2;
        int na=upper_bound(all(a),mid)-a.begin();
        int nb=b.end()-lower_bound(all(b),mid);
        if (na>=nb) r=mid;
        else l=mid+1;
    }
    print(l);

    return 0;
}
