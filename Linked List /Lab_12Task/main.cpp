#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to build the perfect tree you described
Node* buildPerfectTree(int level, int val) {
    if (level < 0) return nullptr;
    Node* root = new Node(val);
    root->left = buildPerfectTree(level - 1, val / 2);
    root->right = buildPerfectTree(level - 1, val / 2);
    return root;
}

void printTree(Node* root) {
    if (!root) return;

    // We store levels in a vector of vectors
    vector<Node*> current_level;
    vector<Node*> next_level;
    current_level.push_back(root);

    int depth = 4; // Height of our specific tree
    int cell_width = 2; // Width of the number being printed

    for (int i = 0; i < depth; i++) {
        // 1. Calculate spacing for the current level
        int initial_padding = pow(2, depth - i - 1) * 2 - 2;
        int between_padding = pow(2, depth - i) * 2 - 2;

        // Print leading spaces
        cout << string(initial_padding, ' ');

        // 2. Print the nodes
        for (Node* n : current_level) {
            if (n) {
                cout << setw(cell_width) << n->data;
                next_level.push_back(n->left);
                next_level.push_back(n->right);
            } else {
                cout << "  "; // Empty space for null nodes
                next_level.push_back(nullptr);
                next_level.push_back(nullptr);
            }
            // Space between nodes in the same row
            cout << string(between_padding, ' ');
        }
        cout << endl;

        // 3. Print the slashes (only if not the last level)
        if (i < depth - 1) {
            int slash_padding = initial_padding - 1;
            int slash_gap = between_padding - 2;
            int branch_gap = 2;

            cout << string(max(0, slash_padding), ' ');
            for (int j = 0; j < current_level.size(); j++) {
                cout << "/";
                cout << string(branch_gap, ' ');
                cout << "\\";
                cout << string(max(0, slash_gap - 2), ' ');
            }
            cout << endl;
        }

        current_level = next_level;
        next_level.clear();
    }
}

int main() {
    // Dynamically build the tree: 8 -> 4s -> 2s -> 1s
    Node* root = buildPerfectTree(3, 8);

    cout << "Dynamic Tree Visualization:" << endl << endl;
    printTree(root);

    return 0;
}