#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;
    BST(vector<int>input) {
        root = construct(input, 0, input.size() - 1);
    }
    TreeNode* construct(vector<int>input, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) {
            return new TreeNode(input[l]);
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(input[mid]);
        root->left = construct(input, l, mid - 1);
        root->right = construct(input, mid + 1, r);
        return root;
    }
    void traverse(TreeNode* root) {
        if(!root) return;
        traverse(root->left);
        printf("%d ", root->val);
        traverse(root->right);
    }
};

int main() {
    vector<int>input = vector<int>{1, 2, 3, 4, 5};
    BST bst = BST(input);
    bst.traverse(bst.root);
    return 0;
}