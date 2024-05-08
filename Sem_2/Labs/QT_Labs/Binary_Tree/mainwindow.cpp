#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = nullptr;
}
MainWindow::~MainWindow()
{
    delete ui;
    if (view != nullptr)
        delete view;
}
void preorder(Node* root, QString& result)
{
    if (root == nullptr)
    {
        return;
    }
    result += QString::number(root->key) + " ";
    preorder(root->left, result);
    preorder(root->right, result);
}
void inorder(Node* root, QString& result)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, result);
    result += QString::number(root->key) + " ";
    inorder(root->right, result);
}
void postorder(Node* root, QString& result)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left, result);
    postorder(root->right, result);
    result += QString::number(root->key) + " ";
}
void MainWindow::updateTreeView()
{
    if (view != nullptr)
    {
        delete view;
    }
    view = new BinaryTreeView(root, this);
    view->resize(1000, 530);
    view->show();
}
void MainWindow::on_ButtonCreateTree_clicked()
{
    root = new Node(rand()%100-rand()%100);
    for(int i = 0; i < rand()%100; i++)
    {
        insert(root, (rand()%100-rand()%100));
    }
    updateTreeView();
    ui->statusbar->showMessage("Дерево успешно создано!");
}
void MainWindow::on_InsertNode_clicked()
{
    QString value = ui->lineEdit->text();
    int key = value.toInt();
    insert(root, key);
    updateTreeView();
    ui->lineEdit->clear();
    ui->statusbar->showMessage("Узел успешно вставлен!");
}
void MainWindow::on_DeleteNode_clicked()
{
    QString value = ui->lineEdit_2->text();
    int key = value.toInt();
    deleteNode(root, key);
    updateTreeView();
    ui->lineEdit_2->clear();
    ui->statusbar->showMessage("Узел успешно удалён!");
}
void MainWindow::on_ButtonCreateTreeNULL_clicked()
{
    root = new Node(0);
    updateTreeView();
    ui->statusbar->showMessage("Пустое дерево успешно создано!");
}
void MainWindow::on_Button_Pre_In_Post_Order_clicked()
{
    ui->textBrowser->clear();
    QString result;
    result = "preorder: ";
    preorder(root, result);
    ui->textBrowser->append(result);

    result = "inorder: ";
    inorder(root, result);
    ui->textBrowser->append(result);

    result = "postorder: ";
    postorder(root, result);
    ui->textBrowser->append(result);
    ui->statusbar->showMessage("Алгоритмы: прямой, симметричный, обратный успешно выполнены!");
}
void MainWindow::on_ButtonBalanceTree_clicked()
{
    if (root == nullptr)
    {
        ui->statusbar->showMessage("Дерево пусто!");
        return;
    }

    Node* newRoot = balanceTree(root);
    if (newRoot != nullptr) {
        deleteTree(root);
        root = newRoot;
        updateTreeView();
        ui->statusbar->showMessage("Дерево успешно сбалансировано!");
    } else {
        ui->statusbar->showMessage("Ошибка при балансировке дерева!");
    }
}
void MainWindow::on_ButtonDeleteTree_clicked()
{
    deleteTree(root);
    updateTreeView();
    ui->statusbar->showMessage("Дерево успешно уничтожено!");
}

Node* findMax(Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    Node* current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}
void MainWindow::on_ButtonFindMax_clicked()
{
    if (root == nullptr)
    {
        ui->statusbar->showMessage("Дерево пусто!");
        return;
    }
    Node* maxNode = findMax(root);
    if (maxNode != nullptr)
    {
        ui->statusbar->showMessage("Максимальный элемент: " + QString::number(maxNode->key));
    }
    else
    {
        ui->statusbar->showMessage("Максимальный элемент не найден!");
    }
}
