// https://atcoder.jp/contests/abc453/tasks/abc453_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t,x;
    cin >> t >> x;
    vi a(t+1);
    cin >> a;
    int lt=0,la=a[lt];
    print(lt,la);
    rep1(i,t) {
        if (abs(la-a[i])>=x) {
            lt=i,la=a[lt];
            print(lt,la);
        }
    }

    return 0;
}
