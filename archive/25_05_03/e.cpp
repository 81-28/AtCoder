// https://atcoder.jp/contests/abc404/tasks/abc404_e

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi c(n,0),a(n,0);
    rep1(i,n-1) cin >> c[i];
    rep1(i,n-1) cin >> a[i];

    // d[i][j]: jからiまで行く最短回数(i<j)
    vvi d(n,vi(n,INT_MAX));
    for (int i=0; i<n-1; i++) {
        d[i][i]=0;
        for (int j=i+1; j<n; j++) {
            d[i][j]=*min_element(d[i].begin()+max(j-c[j],i),d[i].begin()+j)+1;
        }
    }
    int ans=0;
    int add;
    for (int i=n-1; i>0; i--) {
        if (a[i]) {
            add=d[0][i];
            for (int j=1; j<i; j++) {
                if (a[j]) add=min(add,d[j][i]);
            }
            ans+=add;
        }
    }
    print(ans);

    return 0;
}
