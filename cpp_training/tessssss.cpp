#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cout << "hello world" << std::endl;
    std::map<std::string, int> array;
    array["johny"] = 21;
    for(auto x : array) {
        std::cout << x.first << "\t" << x.second << "\n";   
    }
    return 0;
}