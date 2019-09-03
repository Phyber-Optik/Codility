#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> get_power_sets(vector<int>items, int index) {
    if(index == items.size()) {
        vector<vector<int>>result = vector<vector<int>>();
        result.push_back(vector<int>());
        return result;
    }
    vector<vector<int>>ret = get_power_sets(items, index + 1);
    vector<vector<int>>temp(ret);
    for(auto v: ret) {
        v.push_back(items[index]);
        temp.push_back(v);
    }
    return temp;
}

int main() {
    for(auto v: get_power_sets(vector<int>{1, 2, 3}, 0)) {
        for(int x: v) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}