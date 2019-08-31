#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    pair<int, bool> check_height(TreeNode* node) {
        if(!node) return pair<int, bool>(0, true);
        pair<int, bool>left = check_height(node->left);
        pair<int, bool>right = check_height(node->right);
        return pair<int, bool>(max(left.first, right.first) + 1, left.second & right.second & abs(left.first-right.first) <= 1);
    }
    bool isBalanced(TreeNode* root) {
        return check_height(root).second;
    }
};