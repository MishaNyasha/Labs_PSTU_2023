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
    if (root == nullptr)
    {
        return;
    }
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
Node* balanceTree(Node* root)
{
    std::vector<int> values;
    storeInorder(root, values);
    if (values.empty())
    {
        return nullptr;
    }
    std::sort(values.begin(), values.end());
    return buildBalancedTree(values, 0, values.size() - 1);
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
    if (newRoot != nullptr)
    {
        deleteTree(root);
        root = newRoot;
        updateTreeView();
        ui->statusbar->showMessage("Дерево успешно сбалансировано!");
    }
    else
    {
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
