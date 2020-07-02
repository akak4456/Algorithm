#include <iostream>
#include <string>
using namespace std;
typedef int Key;
struct TreeNode {
    bool isBlack = true;
    Key key = -1;
    TreeNode* parent = NULL;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
};
TreeNode* bstSearch(TreeNode* root, Key k) {
    if (root == NULL)
        return NULL;
    else {
        if (k == root->key)
            return root;
        else if (k < root->key)
            return bstSearch(root->left, k);
        else
            return bstSearch(root->right, k);
    }
}
TreeNode* doubleRedChild(TreeNode* root) {
    if (root != NULL && !root->isBlack) {
        if (root->left != NULL && !root->left->isBlack)
            return root->left;
        if (root->right != NULL && !root->right->isBlack)
            return root->right;
    }
    return NULL;
}
TreeNode* recoloringOrReStructuring(TreeNode* ancestor, TreeNode* parent, TreeNode* child) {
    if (child == NULL)
        return NULL;
    TreeNode* cousin = NULL;
    if (ancestor->left != NULL && ancestor->left->key != parent->key) {
        cousin = ancestor->left;
    }
    else if (ancestor->right != NULL && ancestor->right->key != parent->key) {
        cousin = ancestor->right;
    }
    if (cousin != NULL)
        cout << cousin->key << endl;
    if (cousin != NULL && !cousin->isBlack) {
        cout << "RECOLORING\n";
        cousin->isBlack = true;
        parent->isBlack = true;
        ancestor->isBlack = false;
        return ancestor;
    }
    else {
        cout << "RESTRUCTURING\n";
        TreeNode* firstNode = NULL;
        TreeNode* secondNode = NULL;
        TreeNode* thirdNode = NULL;
        if (ancestor->key > parent->key) {
            if (ancestor->key > parent->key) {
                thirdNode = ancestor;
                if (parent->key > child->key) {
                    firstNode = child;
                    secondNode = parent;
                }
                else {
                    firstNode = parent;
                    secondNode = child;
                }
            }
            else {
                firstNode = parent;
                secondNode = ancestor;
                thirdNode = child;
            }
        }
        else {
            if (ancestor->key > child->key) {
                firstNode = child;
                secondNode = ancestor;
                thirdNode = parent;
            }
            else {
                firstNode = ancestor;
                if (parent->key > child->key) {
                    secondNode = child;
                    thirdNode = parent;
                }
                else {
                    secondNode = parent;
                    thirdNode = child;
                }
            }
        }
        cout << firstNode->key << ' ' << secondNode->key << ' ' << thirdNode->key << endl;
        firstNode->parent = secondNode;
        secondNode->parent = ancestor;
        thirdNode->parent = secondNode;
        if (secondNode->left != firstNode) {
            firstNode->right = secondNode->left;
        }
        if (secondNode->right != thirdNode) {
            thirdNode->left = secondNode->right;
        }
        secondNode->left = firstNode;
        secondNode->right = thirdNode;
        firstNode->isBlack = false;
        secondNode->isBlack = true;
        thirdNode->isBlack = false;
        return secondNode;
    }
    return NULL;
}
TreeNode* insertNode(TreeNode* root, Key k,bool isRoot) {
    if (root == NULL) {
        root = new TreeNode();
        root->key = k;
        if (!isRoot) {
            root->isBlack = false;
        }
        return root;
    }
    TreeNode* newNode = NULL;
    if (k < root->key) {
        //root:parent newNode:child
        newNode = insertNode(root->left, k,false);
        root->left = newNode;
        newNode->parent = root;
    }
    else if (k > root->key) {
        newNode = insertNode(root->right, k,false);
        root->right = newNode;
        newNode->parent = root;
    }
    TreeNode* afterNode1 = recoloringOrReStructuring(root, root->left, doubleRedChild(root->left));
    TreeNode* afterNode2 = recoloringOrReStructuring(root, root->right, doubleRedChild(root->right));
    if (afterNode1 != NULL){
    	root = afterNode1;
	}else if(afterNode2 != NULL){
		root = afterNode2;
	} 
    return root;
}
void showTree(TreeNode* root, int depth) {
    if (root == NULL)
        return;
    for (int i = 0; i < depth; i++) {
        cout << '#';
    }
    cout << root->key << " IS ";
    if (root->isBlack) {
        cout << "BLACK"<<endl;
    }
    else {
        cout << "RED" << endl;
    }
    if (root->left != NULL) {
        cout << "LEFT OF "<<root->key<<":";
        showTree(root->left, depth + 1);
    }
    if (root->right != NULL) {
        cout << "RIGHT OF " << root->key << ":";;
        showTree(root->right, depth + 1);
    }
}
void leftRotate(TreeNode** root,TreeNode* x){
	TreeNode* y = x->right;
	x->right = y->left;
	y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL){
		*root = y;
	}else if(x == x->parent->left){
		x->parent->left = y;
	}else{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
	
}
void rightRotate(TreeNode** root,TreeNode* y){
	TreeNode* x = x->left;
	y->left = x->right;
	if(x->right != NULL){
		x->right->parent = y;
	}
	x->parent = y->parent;
	if(y->parent == NULL){
		*root = x;
	}else if(y == y->parent->left){
		y->parent->left = x;
	}else{
		y->parent->right = x;
	}
	x->right = y;
	y->parent = x;
}
void deleteFixUp(TreeNode* root,TreeNode* x){
	while(x != root && x->isBlack == true){
		if(x == x->parent->left){
			TreeNode* w = x->parent->right;
			if(w->isBlack == false){
				w->isBlack = true;
				x->parent->isBlack = false;
				leftRotate(&root,x->parent);
				w = x->parent->right;
			}
			else if(w->left->isBlack&&w->right->isBlack){
				w->isBlack = false;
				x = x->parent;
			}
			else if(w->right->isBlack){
				w->left->isBlack = true;
				w->isBlack = false;
				rightRotate(&root,w);
				w = x->parent->right;
			}else{
				w->isBlack = x->parent->isBlack;
				x->parent->isBlack = true;
				w->right->isBlack = true;
				leftRotate(&root,x->parent);
				x = root;
			}
		}else if(x == x->parent->right){
			TreeNode* w = x->parent->left;
			if(w->isBlack == false){
				w->isBlack = true;
				x->parent->isBlack = false;
				rightRotate(&root,x->parent);
				w = x->parent->left;
			}
			else if(w->left->isBlack&&w->right->isBlack){
				w->isBlack = false;
				x = x->parent;
			}
			else if(w->right->isBlack){
				w->left->isBlack = true;
				w->isBlack = false;
				leftRotate(&root,w);
				w = x->parent->left;
			}else{
				w->isBlack = x->parent->isBlack;
				x->parent->isBlack = true;
				w->right->isBlack = true;
				rightRotate(&root,x->parent);
				x = root;
			}
		}
	}
	x->isBlack = true;
}
TreeNode* deleteNode(TreeNode** root,Key key){
	TreeNode* z = bstSearch(*root,key);
	TreeNode* y = NULL;
	if(z->left == NULL || z->right == NULL){
		y = z;
	}else{
		TreeNode* successor = z->right;
		while(successor->left != NULL){
			successor = successor->left;
		}
		y = successor;
	}
	TreeNode* x = NULL;
	if(y->left != NULL){
		x = y->left;
	}else{
		x = y->right;
	}
	if(x != NULL)
		x->parent = y->parent;
	//cout <<y << ' '<< y->parent->right << ' '<<y->parent->left << endl;
	if(y->parent == NULL){
		*root = x;
	}else if(y == y->parent->left){
		y->parent->left = x;
	}else if(y == y->parent->right){
		y->parent->right = x;
	}
	
	if(y != z){
		z->key = y->key;
	}
	if(y->isBlack){
		deleteFixUp(*root,x);
	}
	return y;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    TreeNode* root = NULL;
    while (true) {
        Key k;
       	string s;
        cin >> s;
        if (s == "quit")
            break;
        if(s == "insert"){
        	cin >> k;
        	root = insertNode(root, k,true);
        	root->isBlack = true;
        	cout << "The Tree is" << endl;
        	showTree(root, 0);
        }else if(s == "delete"){
        	cin >> k;
        	delete deleteNode(&root,k);
        	cout << "The Tree is\n";
        	showTree(root,0);
		}
    }
}
