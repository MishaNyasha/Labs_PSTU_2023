#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
//---Создание дерева
void MainWindow::on_ButtonCreateTree_clicked()
{
    root = new Node(5);
    for(int i = 0; i < 10; i++)
    {
        insert(root, (rand()%10));
    }
    BinaryTreeView* view = new BinaryTreeView(root);
    view->resize(1300, 800);
    view->show();
    ui->statusbar->showMessage("Дерево успешно создано!");
}
//---Вставка узла
void MainWindow::on_InsertNode_clicked()
{
    QString value = ui->lineEdit->text();
    int key = value.toInt();
    insert(root, key);
    update();
    ui->statusbar->showMessage("Узел успешно вставлен!");
}
//---Удаление узла
void MainWindow::on_DeleteNode_clicked()
{
    QString value = ui->lineEdit_2->text();
    int key = value.toInt();
    deleteNode(root, key);
    update();
    ui->statusbar->showMessage("Узел успешно удалён!");
}
//---Создание пустого дерева
void MainWindow::on_ButtonCreateTreeNULL_clicked()
{
    root = new Node(0);
    BinaryTreeView* view = new BinaryTreeView(root);
    view->resize(1300, 800);
    view->show();
    ui->statusbar->showMessage("Пустое дерево успешно создано!");
}
//---Вывод в консоль алгоритмов обхода
void MainWindow::on_Button_Pre_In_Post_Order_clicked()
{
    ui->statusbar->showMessage("Алгоритмы: прямой, симметричный, обратный успешно выполнены!");
    std::cout << std::endl << "preorder: ";
    preorder(root);
    std::cout << std::endl << "inorder: ";
    inorder(root);
    std::cout << std::endl << "postorder: ";
    postorder(root);
    std::cout << std::endl;
}
//---Балансировка дерева
void MainWindow::on_ButtonBalanceTree_clicked()
{
    balanceTree(root);
    ui->statusbar->showMessage("Дерево успешно сбалансировано!");
}
//---Удаление Дерева
void MainWindow::on_ButtonDeleteTree_clicked()
{
    deleteTree(root);
    ui->statusbar->showMessage("Дерево успешно уничтоженно!");
}
//---Поиск максимального элемента
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
