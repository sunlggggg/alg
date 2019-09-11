#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



template <typename T>
struct cmp
{
    bool operator()(const T &x, const T &y)
    {
        return y>x;
    }
};


int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    sort(v.begin(), v.end(), cmp<int>());
    for (int i = 0; i < 3; ++i) {
        cout << v[i] << endl;
    }
    return 0;
}