#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int cnt0 = 0, cnt1 = 0;

int miniEdit(string src, string dest) {
    cnt0++;
    if (src.length() == 0 || dest.length() == 0) {
        return max(src.length(), dest.length());
    } else if (src[0] == dest[0]) {
        return miniEdit(src.substr(1), dest.substr(1));
    } else {
        // Insert,Delete,Replace
        return 1 + min(min(miniEdit(src, dest.substr(1)), miniEdit(src.substr(1), dest)),
                       miniEdit(src.substr(1), dest.substr(1)));
    }
}


int miniEditFromBottom(string src, string dest) {
    int miniEdit[1000][1000];


    miniEdit[src.length()][dest.length()] = 0;

    for (int k = src.length() - 1; k >= 0; --k) {
        miniEdit[k][dest.length()] = src.length() - k;
        cnt1++;
    }

    for (int k = dest.length() - 1; k >= 0; --k) {
        miniEdit[src.length()][k] = dest.length() - k;
        cnt1++;
    }

    for (int i = src.length() - 1; i >= 0; --i) {
        for (int j = dest.length() - 1; j >= 0; --j) {
            cnt1++;
            if (src[i] == dest[j]) {
                miniEdit[i][j] = miniEdit[i + 1][j + 1];
            } else {
                // Insert Delete Replace
                miniEdit[i][j] = 1 + min(min(miniEdit[i][j + 1], miniEdit[i + 1][j]), miniEdit[i + 1][j + 1]);
            }
        }
    }
    return miniEdit[0][0];
}


int main() {
    string src, dest;
    cin >> src >> dest;
    if (miniEditFromBottom(src, dest) == miniEdit(src, dest)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << cnt0 << " " << cnt1 << endl;
}