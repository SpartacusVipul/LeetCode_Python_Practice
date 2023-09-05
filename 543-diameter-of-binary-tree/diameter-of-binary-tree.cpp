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
class Solution {
public:
    // calcualte left height and right height, 
    // if left height + righheight > currentMaxDiamter update currentMaxDiameter
    // now, return height as max of left or right + 1
    int getHeight(TreeNode* root, int &maxDiameter) {
        if (root == NULL) return 0;
        int lh = getHeight(root->left, maxDiameter);
        int rh = getHeight(root->right, maxDiameter);
        // here it is just lh + rh because the diameter doesnt increase because of root at this position
        maxDiameter = max(maxDiameter, lh + rh); 
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        int dummy = getHeight(root, maxDiameter);
        return maxDiameter;
    }
};