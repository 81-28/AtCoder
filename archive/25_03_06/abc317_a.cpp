// https://atcoder.jp/contests/abc317/tasks/abc317_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
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

    int n,h,x;
    cin >> n >> h >> x;
    vi p(n);
    cin >> p;
    x-=h;
    rep(i,n) {
        if(p[i]>=x) {
            print(i+1);
            break;
        }
    }

    return 0;
}
