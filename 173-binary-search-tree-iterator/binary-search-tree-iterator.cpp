/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> stack;
    BSTIterator(TreeNode* root) {
        TreeNode *temp = root;
        while (temp != NULL) {
            stack.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        TreeNode *top = stack.top();
        stack.pop();
        int ret = top->val;
        if (top->right != NULL) {
            TreeNode *temp = top->right;
            while (temp != NULL) {
                stack.push(temp);
                temp = temp->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return stack.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */