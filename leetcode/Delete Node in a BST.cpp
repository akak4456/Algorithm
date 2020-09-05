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
    TreeNode* findNode(TreeNode* root,int key){
         if(root == nullptr){
            return nullptr;
        }
        if(root->val == key){
            return root;
        }
        TreeNode* ret = nullptr;
        TreeNode* tmp = findNode(root->left,key);
        if(tmp != nullptr){
            ret = tmp;
        }
        tmp = findNode(root->right,key);
        if(tmp != nullptr){
            ret=  tmp;
        }
        return ret;
    }
    TreeNode* getParent(TreeNode* root,TreeNode* target){
        if(root == nullptr){
            return nullptr;
        }
        if(root->left == target || root->right == target){
            return root;
        }
        TreeNode* ret = nullptr;
        TreeNode* tmp = getParent(root->left,target);
        if(tmp != nullptr){
            ret = tmp;
        }
        tmp = getParent(root->right,target);
        if(tmp != nullptr){
            ret = tmp;
        }
        return ret;
    }
    TreeNode* newRoot;
    void delNode(TreeNode* target){
        //root 반환
        TreeNode* parNode = getParent(newRoot,target);
        if(target->left == nullptr && target->right == nullptr){
             //자식없음
            if(parNode == nullptr){
                newRoot = nullptr;
            }else if(parNode->left == target){
                 parNode->left = nullptr;
             }else{
                 parNode->right = nullptr;
             }
             delete target;
        }else if(target->left == nullptr){
            if(parNode == nullptr){
                newRoot = target->right;
            }else if(parNode->left == target){
                parNode->left = target->right;
            }else{
                parNode->right = target->right;
            }
            delete target;
        }else if(target->right == nullptr){
            if(parNode == nullptr){
                newRoot = target->left;
            }else if(parNode->left == target){
                parNode->left = target->left;
            }else{
                parNode->right = target->left;
            }
            delete target;
        }else{
            TreeNode* leftMost = target->right;
            while(leftMost->left != nullptr){
                leftMost = leftMost->left;
            }
            target->val = leftMost->val;
            delNode(leftMost);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        newRoot = root;
        TreeNode* target = findNode(root,key);
        if(target == nullptr){
            return newRoot;
        }
        delNode(target);
        return newRoot;
        // TreeNode* findedNode = findNode(root,key);
        // TreeNode* parNode = getParent(root,findedNode);
        // if(findedNode->left == nullptr && findedNode->right == nullptr){
        //     //자식없음
        //     if(parNode->left == findedNode){
        //         parNode->left = nullptr;
        //     }else{
        //         parNode->right = nullptr;
        //     }
        //     delete findedNode;
        // }else if(findedNode->left == nullptr){
        //     if(parNode->left == findedNode){
        //         parNode->left = findedNode->right;
        //     }else{
        //         parNode->right = findedNode->right;
        //     }
        //     delete findedNode;
        // }else if(findedNode->right == nullptr){
        //     if(parNode->left == findedNode){
        //         parNode->left = findedNode->left;
        //     }else{
        //         parNode->right = findedNode->left;
        //     }
        //     delete findedNode;
        // }else{
        //     //자식 두개 있음
        //     TreeNode* leftMost = findedNode->right;
        //     while(leftMost->left != nullptr){
        //         leftMost = leftMost->left;
        //     }
        // }
        // return root;
    }
};