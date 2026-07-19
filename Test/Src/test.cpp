#include <iostream>
#include <string>
#include <fmt/core.h>
#include <head.hpp>


int main(){
    std::cout<<"Hello world!"<<std::endl;
    int a = 1;
    int b = 2;
    int result;
    Add(a, b, result);
    std::cout<<result<<std::endl;

    std::string name = "Alice";
    std::string msg = fmt::format("{0} is {1}\n", name, 18);
    fmt::print(msg);

}