/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
private:
    void dfs(Node* node) {
        if (node == nullptr) return;
        ans.push_back(node->val);
        vector<Node*> c = node->children;
        for (int i = 0; i < c.size(); i++)
            dfs(c[i]);
    }
};