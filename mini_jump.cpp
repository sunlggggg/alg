#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

// 计算最少需要跳跃的次数
// -1 不可达
int mini(vector<int> v){
    int *dis = new int[v.size()];
    dis[v.size() - 1] = 0 ;
    for(int i = v.size() - 2 ; i >= 0 ; i -- ){
        if(v[i] == 0 ){
            dis[i] = 0xffff;
        } else {
            int min = 0xffff;
            for(int j = 1; j <= v[i] && i + j < v.size() ; j++){
                if(1 + dis[i + j ] < min )	{
                    min = 1 + dis[i+j];
                }
            }
            dis[i] = min;
        }
    }
    if(dis[0] >= 0xffff){
        return -1;
    }
    return dis[0];
}

int main(){
    vector<int> v;
    int n;
    while(cin >> n){
        v.push_back(n);
        if(cin.get() == '\n'){
            break;
        }
    }
    cout << mini(v) << endl;
    return 0;
}
