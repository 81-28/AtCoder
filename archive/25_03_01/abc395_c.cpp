// https://atcoder.jp/contests/abc395/tasks/abc395_c

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int ans=INT_MAX;
    map<int,int> m;
    int a;
    rep1(i,n) {
        cin >> a;
        if (m[a]) {
            ans = min(ans,i-m[a]+1);
        }
        m[a]=i;
    }
    print(ans==INT_MAX ? -1 : ans);


    return 0;
}
