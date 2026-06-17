#include <iostream>
#include <vector>
#include <string>
#include "RedBlackTree.h"

using namespace std;
void preorder(
    const RedBlackTree::Node* node,
    const RedBlackTree::Node* nil,
    vector<int>& result)
{
    if (node == nil) return;
    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}
void inorder(
    const RedBlackTree::Node* node,
    const RedBlackTree::Node* nil,
    vector<int>& result)
{
    if (node == nil) return;
    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}
void postorder(
    const RedBlackTree::Node* node,
    const RedBlackTree::Node* nil,
    vector<int>& result)
{
    if (node == nil) return;
    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}
void printTraversal(
    const string& name,
    const vector<int>& values)
{
    cout << "[" << name << "] : ";
    for (size_t i = 0; i < values.size(); i++) {
        if (i) cout << ' ';
        cout << values[i];
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    RedBlackTree tree;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        tree.insert(x);
    }
    int Q;
    cin >> Q;
    if (tree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        return 0;
    }
    while (Q--) {
        string query;
        cin >> query;
        if (query == "PREORDER") {
            vector<int> res;
            preorder(tree.root(), tree.nil(), res);
            printTraversal("Preorder", res);
        }
        else if (query == "INORDER") {
            vector<int> res;
            inorder(tree.root(), tree.nil(), res);
            printTraversal("Inorder", res);
        }
        else if (query == "POSTORDER") {
            vector<int> res;
            postorder(tree.root(), tree.nil(), res);
            printTraversal("Postorder", res);
        }
        else if (query == "ALL") {
            vector<int> pre;
            vector<int> in;
            vector<int> post;
            preorder(tree.root(), tree.nil(), pre);
            inorder(tree.root(), tree.nil(), in);
            postorder(tree.root(), tree.nil(), post);
            printTraversal("Preorder", pre);
            printTraversal("Inorder", in);
            printTraversal("Postorder", post);
        }
    }
    return 0;
}