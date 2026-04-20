// https://atcoder.jp/contests/abc252/tasks/abc252_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    map<int,int> m;
    for (int val:a) ++m[val];
    int ans=n*(n-1)*(n-2)/6;
    for (auto[num,c]:m) {
        // 選んだ数の内2つが等しい場合
        ans-=c*(c-1)/2*(n-c);
        // 選んだ数の内3つが等しい場合
        ans-=c*(c-1)*(c-2)/6;
    }
    print(ans);

    return 0;
}
