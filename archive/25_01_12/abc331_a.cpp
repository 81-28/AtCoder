// https://atcoder.jp/contests/abc331/tasks/abc331_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m,d;
    int yy,mm,dd;
    cin >> m >> d >> yy >> mm >> dd;
    dd++;
    if (dd > d) {
        dd=1;
        mm++;
        if (mm > m) {
            mm=1;
            yy++;
        }
    }
    print(yy,mm,dd);

    return 0;
}
