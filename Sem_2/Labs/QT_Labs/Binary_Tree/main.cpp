#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include <iostream>
#include "mainwindow.h"
#include <vector>
#include <algorithm>
void deleteTree(Node* &root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}
Node* findMin(Node* node)
{
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
void deleteNode(Node* &root, int key)
{
    if (root == nullptr)
    {
        return;
    }

    if (key < root->key)
    {
        deleteNode(root->left, key);
    } else if (key > root->key)
    {
        deleteNode(root->right, key);
    } else {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            root = temp;
        } else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            deleteNode(root->right, temp->key);
        }
    }
}
void insert(Node* root, int key)
{
    if (key < root->key)
    {
        if (root->left == nullptr)
        {
            root->left = new Node(key);
        } else
        {
            insert(root->left, key);
        }
    } else
    {
        if (root->right == nullptr)
        {
            root->right = new Node(key);
        } else
        {
            insert(root->right, key);
        }
    }
}
void storeInorder(Node* root, std::vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }
    storeInorder(root->left, values);
    values.push_back(root->key);
    storeInorder(root->right, values);
}
Node* buildBalancedTree(const std::vector<int> &values, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(values[mid]);
    root->left = buildBalancedTree(values, start, mid - 1);
    root->right = buildBalancedTree(values, mid + 1, end);
    return root;
}
Node* balanceTree(Node* root) {
    std::vector<int> values;
    storeInorder(root, values);
    if (values.empty()) {
        return nullptr;
    }
    std::sort(values.begin(), values.end());
    return buildBalancedTree(values, 0, values.size() - 1);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
