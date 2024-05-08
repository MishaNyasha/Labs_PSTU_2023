#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <QApplication>
#include <QWidget>
#include <QFont>
#include <iostream>
#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
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
Node* balanceTree(Node* root);
class BinaryTreeView : public QGraphicsView
{
public:
    BinaryTreeView(Node* root, QWidget* parent = nullptr) : QGraphicsView(parent), m_root(root)
    {
        scene = new QGraphicsScene(this);
        setScene(scene);
        drawTree(m_root, 630, 50);
    }
private:
    QGraphicsScene* scene;
    Node* m_root;
    int getDepth(Node* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
    void drawTree(Node* node, int x, int y)
    {
        if (node == nullptr)
        {
            return;
        }
        QPen linePen(Qt::magenta);
        linePen.setWidth(2);
        QBrush circleBrush(Qt::white);
        scene->addEllipse(x, y, 40, 40, linePen, circleBrush);
        int offsetX_l = 30 * pow(2, getDepth(node->left) - 1);
        int offsetX_r = 30 * pow(2, getDepth(node->right) - 1);
        int offsetY = 70;
        QFont font("Arial", 12);
        QGraphicsTextItem* textItem = scene->addText(QString::number(node->key), font);
        textItem->setPos(x, y);
        if (node->left != nullptr)
        {
            scene->addLine(x + 20, y + 40, x - offsetX_l + 20, y + offsetY, linePen);
            drawTree(node->left, x - offsetX_l, y + offsetY);
        }
        if (node->right != nullptr)
        {
            scene->addLine(x + 40, y + 20, x + offsetX_r + 20, y + offsetY, linePen);
            drawTree(node->right, x + offsetX_r, y + offsetY);
        }
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
#endif // MAINWINDOW_H
