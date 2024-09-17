#include <iostream>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
 public:
  TreeNode *root;

  BST() : root(NULL) {}

  void insert(int key) {
    root = insertRec(root, key);
  }

  int findHeight() {
    return findHeightRec(root);
  }

 private:
  TreeNode *insertRec(TreeNode *node, int key) {
    if (node == NULL) {
      return new TreeNode(key);
    }
    if (key < node->val) {
      node->left = insertRec(node->left, key);
    } else {
      node->right = insertRec(node->right, key);
    }
    return node;
  }

  int findHeightRec(TreeNode *node) {
    if (node == NULL) {
      return -1;
    }
    int leftHeight = findHeightRec(node->left);
    int rightHeight = findHeightRec(node->right);
    return 1 + max(leftHeight, rightHeight);
  }
};

int main() {
  BST tree;
  int inputs[] = {3, 1, 5, 0, 2, 4, 6};
  int n = sizeof(inputs) / sizeof(inputs[0]);

  for (int i = 0; i < n; ++i) {
    tree.insert(inputs[i]);
  }

  cout << "The height of the BST is: " << tree.findHeight() << endl;

  return 0;
}