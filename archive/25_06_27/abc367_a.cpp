// https://atcoder.jp/contests/abc367/tasks/abc367_a

#include<iostream>
int main(){
    int a,b,c;
    std::cin>>a>>b>>c;
    puts((a<b)+(b<c)+(c<a)>1?"Yes":"No");
}
