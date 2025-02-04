#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int x) {
            val = x;
            left = right = nullptr;
        }
};

int traverse(Node* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return node->val;
    int leftSum = traverse(node->left);
    int rightSum = traverse(node->right);

    return leftSum + rightSum + node->val;
}
bool isSumTree(Node* root) {
    if (!root) {
        return true;
    }
    // Leaf node
    if (!root->left && !root->right) {
        return true;
    }
    int leftSum = traverse(root->left);
    int rightSum = traverse(root->right);
    return ((root->val == (leftSum + rightSum)) && isSumTree(root->left) && isSumTree(root->right));
}

void test(Node* root, bool expected, const string& testName) {
    bool result = isSumTree(root);
    cout << testName << ": " << (result == expected ? "Passed" : "Failed") << endl;
}

int main() {
    // Test Case 1: A valid Sum Tree
    Node* root1 = new Node(26);
    root1->left = new Node(10);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(6);
    root1->right->right = new Node(3);
    test(root1, true, "Test Case 1");

    // Test Case 2: A tree with only one node (should be a Sum Tree)
    Node* root2 = new Node(10);
    test(root2, true, "Test Case 2");

    // Test Case 3: A tree with a root that does not satisfy the sum property
    Node* root3 = new Node(10);
    root3->left = new Node(5);
    root3->right = new Node(3);
    test(root3, false, "Test Case 3");

    // Test Case 4: An empty tree (should be a Sum Tree)
    test(nullptr, true, "Test Case 4");

    // Test Case 5: A more complex Sum Tree
    Node* root5 = new Node(88);
    root5->left = new Node(18);
    root5->right = new Node(26);
    root5->left->left = new Node(8);
    root5->left->right = new Node(10);
    root5->right->left = new Node(6);
    root5->right->right = new Node(20);
    test(root5, true, "Test Case 5");

    // Test Case 6: A tree where only one subtree satisfies the Sum Tree property
    Node* root6 = new Node(15);
    root6->left = new Node(5);
    root6->right = new Node(10);
    root6->right->left = new Node(4);
    root6->right->right = new Node(6);
    test(root6, false, "Test Case 6");

    return 0;
}