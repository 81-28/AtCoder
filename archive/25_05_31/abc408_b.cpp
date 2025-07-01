// https://atcoder.jp/contests/abc408/tasks/abc408_b

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    set<int> s(all(a));
    print(s.size());
    for (int val:s) cout<<val<<' ';
    cout<<'\n';

    return 0;
}
