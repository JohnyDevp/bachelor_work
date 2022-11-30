#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    using namespace std;
    vector<int> v = {1,2,3,4};

    std::for_each (begin(v), end(v), [](int x) { std::cout << x << "\n";});
    
    return 0;
}