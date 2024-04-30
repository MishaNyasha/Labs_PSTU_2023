#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include <iostream>
#include "mainwindow.h"
#include <vector>
#include <algorithm>
//---Алгоритмы обхода
void preorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
}
void postorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->key << " ";
}
//---Удаление дерева
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
//---Поиск Минимального
Node* findMin(Node* node)
{
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
//---Удаление Узла
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
//---Вставка узла
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
//---Рисование дерева
void BinaryTreeView::drawTree(Node* node, QPainter& painter, int x, int y) {
    if (node == nullptr)
    {
        return;
    }
    QPen linePen(Qt::magenta);
    linePen.setWidth(2);
    QBrush circleBrush(Qt::white);
    painter.setBrush(circleBrush);
    QRect circleRect(x, y, 40, 40);
    painter.drawEllipse(circleRect);
    int offsetX_l = 30 * pow(2, getDepth(node->left) - 1);
    int offsetX_r = 30 * pow(2, getDepth(node->right) - 1);
    int offsetY = 70;
    QFont font("Arial", 12);
    painter.setFont(font);
    QString text = QString::number(node->key);
    painter.setPen(Qt::black);
    painter.drawText(circleRect, Qt::AlignCenter, text);
    if (node->left != nullptr)
    {
        painter.setPen(linePen);
        painter.drawLine(x + 20, y + 40, x - offsetX_l + 20, y + offsetY);
        drawTree(node->left, painter, x - offsetX_l, y + offsetY);
    }
    if (node->right != nullptr)
    {
        painter.setPen(linePen);
        painter.drawLine(x + 40, y + 20, x + offsetX_r + 20, y + offsetY);
        drawTree(node->right, painter, x + offsetX_r, y + offsetY);
    }
}
//---балансировочка (Проблемно)
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
void buildBalancedTree(Node* &root, std::vector<int> &values, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int mid = (start + end) / 2;
    root = new Node(values[mid]);
    buildBalancedTree(root->right, values, start, mid - 1);
    buildBalancedTree(root->left, values, mid + 1, end);
}
void balanceTree(Node* &root)
{
    std::vector<int> values;
    storeInorder(root, values);
    if (values.empty())
    {
        return;
    }
    std::sort(values.begin(), values.end());
    deleteTree(root);
    buildBalancedTree(root, values, 0, values.size() - 1);
}
//---main само собой
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
