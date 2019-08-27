#include<bits/stdc++.h>

using namespace std;

class DinnerPlates {
public:
    int capacity;
    vector<stack<int>>stacks;
    int curMaxIndex;
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        int curIndex = 0;
        while(curIndex < stacks.size() && stacks[curIndex].size() >= capacity) curIndex++;
        // cerr<<"currrr: "<<curIndex<<" "<<val<<endl;
        if(curIndex == stacks.size()) {
            stacks.push_back(stack<int>());
        }
        cerr<<"cur: "<<curIndex<<" "<<val<<" "<<stacks.size()<<endl;
        stacks[curIndex].push(val);
    }
    
    int pop() {
        int curIndex = stacks.size() - 1;
        while(!stacks.empty() && curIndex >= 0 && stacks[curIndex].empty()) {
            stacks.pop_back();
            curIndex--;
        }
        if(stacks.empty()) return -1;
        // cerr<<"del "<<curIndex<<stacks[curIndex].size()<<endl;
        int val = stacks[curIndex].top();
        stacks[curIndex].pop();
        return val;
    }
    
    int popAtStack(int index) {
        if(index >= stacks.size() || stacks[index].size() == 0){
            return -1;
        }
        int val = stacks[index].top();
        stacks[index].pop();
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */