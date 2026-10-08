class Solution {
private:
    unordered_map<long long, int> freq;
    int ans = 0;
    void preorderDfs(TreeNode* root, long long targetSum, long long currentSum) {
        if(root == nullptr) return;
        currentSum += root->val;
        ans += freq[currentSum - targetSum];

        freq[currentSum]++;
        preorderDfs(root->left, targetSum, currentSum);
        preorderDfs(root->right, targetSum, currentSum);
        freq[currentSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        freq[0] = 1;
        preorderDfs(root, targetSum, 0);
        return ans;
    }
};