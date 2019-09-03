#include<bits/stdc++.h>

using namespace std;

vector<string> perm_generator(string input, bool used[], string perm) {
    if(perm.size() >= input.size()) {
        vector<string>ans;
        ans.push_back(perm);
        return ans;
    }
    vector<string>ret;
    for(int i = 0; i < input.size(); i++) {
        if(!used[i]) {
            used[i] = true;
            perm += input[i];
            for(auto x: perm_generator(input, used, perm)) {
                ret.push_back(x);
            }
            used[i] = false;
            perm.pop_back();
        }
    }
    return ret;
}

int main() {
    string input = "abc";
    bool used[input.size()];
    vector<string>ans = perm_generator(input, used, "");
    for(string x: ans) {
        cout<<x<<endl;
    }
}