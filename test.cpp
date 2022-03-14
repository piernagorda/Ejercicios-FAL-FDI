#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::ifstream in("hello.txt");
    auto cinbuf = std::cin.rdbuf();

    std::string temp;
    std::cin>>temp;
    std::cout<<temp<<std::endl;

    return 0;

}