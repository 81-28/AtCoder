// https://atcoder.jp/contests/abc412/tasks/abc412_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int b,e;
        vi s(n-2);
        cin >> b >> s >> e;
        if (b*2>=e) {
            print(2);
            continue;
        }
        multiset<int> se(all(s));
        int ans=0;
        rep1(i,n-2) {
            auto it=se.upper_bound(b*2);
            if (it!=se.begin()) {
                --it;
            } else {
                break;
            }
            b=*it;
            if (b*2>=e) {
                ans=i+2;
                break;
            }
            se.erase(se.find(b));
        }
        print(ans?ans:-1);
    }

    return 0;
}
