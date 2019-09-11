#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
struct cmp {
    bool operator()(const T &x, const T &y) {
    }
};

int getInt() {
    int tmp;
    cin >> tmp;
    return tmp;
}



int main() {

    for (int k = 0; k < 10000000; ++k) {
        cout << k<< " " ;
    }
    return 0;
}