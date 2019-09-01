#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Result {
    bool found_p;
    bool found_q;
    TreeNode* node;
public:
    Result(TreeNode* node): found_p(false), found_q(false), node(node) {}
    Result(TreeNode* node, bool p, bool q): found_p(p), found_q(q), node(node) {}
    void mark_p_as_found() {
        this->found_p = true;
    }
    void mark_q_as_found() {
        this->found_q = true;
    }
    bool are_both_found() {
        return found_p & found_q;
    }
    bool is_p_found() {
        return found_p;
    }
    bool is_q_found() {
        return found_q;
    }
    TreeNode* get_node() {
        return this->node;
    }
};

class Solution {
public:
    Result traverse(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return Result(node);
        Result left = traverse(node->left, p, q);
        Result right = traverse(node->right, p, q);
        if(left.are_both_found()) {
            return left;
        }
        else if(right.are_both_found()) {
            return right;
        }
        else if((left.is_p_found() && right.is_q_found()) || (left.is_q_found() && right.is_q_found())) {
            return Result(node, true, true);
        }
        Result ret = Result(node);
        if(node == p || left.is_p_found() || right.is_p_found()) ret.mark_p_as_found();
        if(node == q || left.is_q_found() || right.is_q_found()) ret.mark_q_as_found();
        return ret; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root, p, q).get_node();
    }
};