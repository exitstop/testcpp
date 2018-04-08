#include <iostream>
#include <string>
#include <cstdint>
 
int main()
{
    std::string str = "hello world";
    std::cout << "0: "<< str.length()  << std::endl;
    std::cout << "1: "<< str.compare("hello")  << std::endl;
    std::cout << "2: "<< str.compare("tello")  << std::endl;
    std::cout << "3: "<< str.compare("hello world")  << std::endl;
    std::cout << "4: "<< str.compare("")  << std::endl;
    
    str = "";
    std::cout << "5: "<< str.compare("tello")  << std::endl;
    std::cout << "6: "<< str.compare("")  << std::endl;
 
}
