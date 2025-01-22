// https://atcoder.jp/contests/abc329/tasks/abc329_d

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    map<int,int> c;
    int a;
    cin >> a;
    c[a]++;
    int idx = a;
    print(idx);
    for (int i=1; i<m; i++) {
        cin >> a;
        c[a]++;
        if (c[idx] == c[a]) {
            idx = min(idx,a);
        } else if (c[idx] < c[a]) {
            idx = a;
        }
        print(idx);
    }

    return 0;
}
