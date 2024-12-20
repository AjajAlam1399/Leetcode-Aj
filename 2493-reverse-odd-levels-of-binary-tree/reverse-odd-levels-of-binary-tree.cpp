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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*>levelOne;
        levelOne.push_back(root);
        

        while(true){
        vector<TreeNode*>levelTwo;
        vector<TreeNode*>levelThree;
            for(int i=0;i<levelOne.size();i++){
                auto it=levelOne[i];
                if(it->left){
                    levelTwo.push_back(it->left);
                    if(it->left->left){
                        levelThree.push_back(it->left->left);
                        levelThree.push_back(it->left->right);
                    }
                }
                if(it->right){
                    levelTwo.push_back(it->right);
                    if(it->right->left){
                        levelThree.push_back(it->right->left);
                        levelThree.push_back(it->right->right);
                    }
                }
            }
            if(levelTwo.size()==0)break;
            int left=0,right=levelTwo.size()-1;
            for(int i=0;i<levelOne.size();i++){
                auto it=levelOne[i];
                it->left=levelTwo[right];
                if(levelThree.size()>0){
                    levelTwo[right]->left=levelThree[left++];
                    levelTwo[right]->right=levelThree[left++];
                }
                right--;
                it->right=levelTwo[right];
                if(levelThree.size()>0){
                    levelTwo[right]->left=levelThree[left++];
                    levelTwo[right]->right=levelThree[left++];
                }
                right--;
            }
            levelOne=levelThree;
        }
        return root;
    }
};