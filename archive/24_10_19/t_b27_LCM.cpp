// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cz
#include<iostream>
int main(){
    long long a,b,c,t;
    std::cin>>a>>b;
    c=a*b;
    while(b!=0){t=b;b=a%b;a=t;}
    std::cout<<c/a<<'\n';
}