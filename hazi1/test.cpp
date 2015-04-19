#include <iostream>
#include <stdexcept>
#include "mystring.h"


int main(){
    MyString a("a");
    {
        MyString b(a);
        MyString c("c");
        MyString v;
        v=b;
        std::cout<<a<<std::endl;
        std::cout<<b<<std::endl;

        std::cout<<c<<std::endl;
        MyString d=c+a+"d";
        std::cout<<d<<std::endl;

        MyString x;
        std::cin>>x;
        std::cout<<x<<std::endl;

    }
    std::cout<<a<<std::endl;

    MyString f(MyString("f"));
    std::cout<<f<<std::endl;

    std::cout<<"adj meg egy indexet!"<<std::endl;
    int i;
    std::cin>>i;
    try{
        std::cout<<f[i]<<std::endl;
    }catch(std::out_of_range const& e){
        std::cout<<"out of range"<<std::endl;
    }
}
