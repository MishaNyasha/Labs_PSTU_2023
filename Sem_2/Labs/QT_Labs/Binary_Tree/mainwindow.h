#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QApplication>
#include <QWidget>
#include <QFont>
#include <iostream>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    Node(int key)
    {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void insert(Node* root, int key);
void deleteNode(Node* &root, int key);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
void deleteTree(Node* &root);
void balanceTree(Node* &root);
class BinaryTreeView : public QWidget 
{
public:
    BinaryTreeView(Node* root, QWidget* parent = nullptr) : QWidget(parent), m_root(root) {}
    void paintEvent(QPaintEvent* event) override
    {
        QPainter painter(this);
        drawTree(m_root, painter, 630, 50);
    }
    void drawTree(Node* node, QPainter& painter, int x, int y);
private:
    Node* m_root;
    int getDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_ButtonCreateTree_clicked();
    void on_InsertNode_clicked();
    void on_DeleteNode_clicked();
    void on_ButtonCreateTreeNULL_clicked();
    void on_Button_Pre_In_Post_Order_clicked();
    void on_ButtonBalanceTree_clicked();
    void on_ButtonDeleteTree_clicked();
    void on_ButtonFindMax_clicked();
private:
    Ui::MainWindow *ui;
    Node* root;
    BinaryTreeView* view;
    void updateTreeView();
};

#endif
