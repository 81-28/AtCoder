// https://atcoder.jp/contests/abc204/tasks/abc204_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vi t(n);
    cin >> t;
    int sm=sum(t);
    set<int> s;
    s.insert(0);
    for (int val:t) {
        for (auto it=s.rbegin(); it!=s.rend(); ++it) s.insert(*it+val);
    }
    print(*s.lower_bound((sm+1)/2));

    return 0;
}
