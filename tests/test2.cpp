#include <iostream>
#include <vector>

int main(){
    std::vector<int> numeros {};
    numeros.push_back(0);
    numeros.push_back(3);
    numeros.push_back(4);
    for(int num:numeros){
        std::cout<<num<<'\n';
    }
    std::cin.get();
    return 0;
}