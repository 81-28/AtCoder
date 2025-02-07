// https://atcoder.jp/contests/abc325/tasks/abc325_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vll a(24,0);
    int j;
    int w,x;
    rep(k,n) {
        cin >> w >> x;
        rep(i,24) {
            j=(i+x)%24;
            if(9<=j && j<18) a[i] += w;
        }
    }
    print(max(a));

    return 0;
}