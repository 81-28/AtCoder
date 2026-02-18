// https://atcoder.jp/contests/abc271/tasks/abc271_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

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
    // 余り　複数冊ある巻は1冊残して余りに回して良い
    int rem=0;
    deque<int> q;
    for (auto[num,cnt]:m) {
        q.pb(num);
        rem+=cnt-1;
    }
    // 必要なときに、最後尾から消費
    rep1(i,n+1) {
        if (!q.empty() && q.front()==i) {
            q.pop_front();
        } else {
            if (rem>1) {
                rem-=2;
            } else if (rem>0) {
                if (q.size()>0) {
                    --rem;
                    q.pop_back();
                } else {
                    print(i-1);
                    return 0;
                }
            } else {
                if (q.size()>1) {
                    q.pop_back();
                    q.pop_back();
                } else {
                    print(i-1);
                    return 0;
                }
            }
        }
    }

    return 0;
}
