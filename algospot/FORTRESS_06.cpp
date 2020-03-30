//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
using namespace std;
int n;
struct Node {
    int x = 0, y = 0, r = 0;
    int height = 0;
    Node* parent = NULL;
    vector<Node*> child;
};
bool sortByHeight(const Node* a, const Node* b) {
    return a->height > b->height;
}
Node* root;
vector<Node*> nodes;
bool isContain(Node* r1, Node* r2) {
    //r1이 r2를 포함?
    return sqrt(pow(r1->x - r2->x, 2) + pow(r1->y - r2->y, 2)) < (r1->r - r2->r);
}
void makeTree(Node* node) {
    for (int i = 0; i < node->child.size(); i++) {
        for (int j = 0; j < node->child.size(); j++) {
            if (i == j)
                continue;
            if (isContain(node->child[i], node->child[j])) {
                node->child[j]->parent = node->child[i];
                node->child[i]->child.push_back(node->child[j]);
                node->child.erase(node->child.begin() + j);
                j--;
            }
        }
    }
    for (int i = 0; i < node->child.size(); i++) {
        makeTree(node->child[i]);
    }
}
void printTree(Node* node,int depth) {
    for (int i = 0; i < depth; i++)
        cout << "L ";
    cout << node->x << ' ' << node->y << ' ' << node->r << ' '<<node->height<< '\n';
    for (int i = 0; i < node->child.size(); i++) {
        printTree(node->child[i],depth+1);
    }
}
int setHeight(Node* node) {
    int h = 0;
    for (int i = 0; i < node->child.size(); i++) {
        h = max(h, setHeight(node->child[i]) + 1);
    }
    node->height = h;
    return h;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            Node* tmp = new Node;
            cin >> tmp->x >> tmp->y >> tmp->r;
            nodes.push_back(tmp);
            if (i == 0) {
                root = tmp;
            }
            else {
                root->child.push_back(tmp);
                tmp->parent = root;
            }
        }  
        makeTree(root);
        setHeight(root);
       // printTree(root,0);
        int ans = 0;
        for (int i = 0; i < nodes.size(); i++) {
            sort(nodes[i]->child.begin(), nodes[i]->child.end(), sortByHeight);
            if (nodes[i]->child.size() == 1)
                ans = max(ans, nodes[i]->child[0]->height+1);
            else if(nodes[i]->child.size() >= 2)
                ans = max(ans, nodes[i]->child[0]->height + nodes[i]->child[1]->height+2);
        }
        cout << ans << '\n';
        for (int i = 0; i < nodes.size(); i++) {
            delete nodes[i];
        }
        nodes.clear();
       // printTree(root, 0);
    }
}