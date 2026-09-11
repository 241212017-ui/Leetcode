class Solution {
public:

    int result = 0;

    int findsum(TreeNode* root, int& count) {

        if (root == NULL)
            return 0;

        count++;

        int lsum = findsum(root->left, count);
        int rsum = findsum(root->right, count);

        return lsum + rsum + root->val;
    }

    void solve(TreeNode* root) {

        if (root == NULL)
            return;

        int count = 0;
        int sum = findsum(root, count);

        if (root->val == sum / count)
            result++;

        solve(root->left);
        solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {

        solve(root);

        return result;
    }
};