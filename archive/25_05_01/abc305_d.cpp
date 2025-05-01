// https://atcoder.jp/contests/abc305/tasks/abc305_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    map<int,pair<int,bool>> m;
    m[0]={0,0};
    for (int i=1; i<n; i++) {
        if (i%2) m[a[i]]={m[a[i-1]].f,1};
        else m[a[i]]={m[a[i-1]].f+(a[i]-a[i-1]),0};
    }
    int q;
    cin >> q;
    int l,r,lt,rt;
    auto itl=a.begin(),itr=a.begin();
    rep(i,q) {
        cin >> l >> r;
        itl=upper_bound(all(a),l);
        itr=upper_bound(all(a),r);
        itl--,itr--;
        lt=m[*itl].f+(m[*itl].s?l-*itl:0);
        rt=m[*itr].f+(m[*itr].s?r-*itr:0);
        print(rt-lt);
    }

    return 0;
}
