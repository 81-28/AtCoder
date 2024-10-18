// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cy
#include<iostream>
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);
    int n;std::cin>>n;
    bool b[n+1];
    for(int i=2;i<=n;i++)b[i]=1;
    for(int i=2;i*i<=n;i++)if(b[i])for(int j=i*i;j<=n;j+=i)b[j]=0;
    for(int i=2;i<=n;i++)if(b[i])std::cout<<i<<'\n';
}