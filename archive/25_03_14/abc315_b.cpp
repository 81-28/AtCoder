// https://atcoder.jp/contests/abc315/tasks/abc315_b

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

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m;
    cin >> m;
    vi d(m);
    cin >> d;
    int s=sum(d);
    int mid=(s+1)/2;
    rep(i,m) {
        if (d[i]<mid) mid-=d[i];
        else {
            print(i+1,mid);
            return 0;
        }
    }

    return 0;
}
