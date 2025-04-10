
class Node {
 public:
  int data;
  Node *left, *right;
};

int floor(Node *root, int key) {
  int floor = -1;
  while (root) {
    if (root->data == key) {
      floor = root->data;
      return floor;
    }

    if (root->data < key) {
      floor = root->data;
      root = root->right;
    } else {
      root = root->left;
    }
  }

  return floor;
}
