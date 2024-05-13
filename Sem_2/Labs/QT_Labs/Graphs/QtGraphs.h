#pragma once
#include <QWidget>
#include <QMouseEvent>
#include <ui_QtGraphs.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Edge;
class Node;
class Graph;
class Node
{
public:
    int data;
    vector<Edge*> edges_to_node;
    QPoint pos;
    bool highlighted;
    Node()
    {
        pos = QPoint(600 + (rand()%600 - 300), 300 + (rand()%600 - 300));
    }
};
class Edge
{
public:
    int weight;
    Node* to;
};
class Graph
{
public:
    unordered_map<int, Node*> nodes_map;

    void DFS(int startData, vector<int>& dfs);
    void BFS(int startData, vector<int>& bfs);
    vector<int> Dijkstra(int startData, int endData);
    void addNode(int data);
    void addEdge(int fromData, int toData, int weight);
    void clearGraph();
    void updateEdgeWeight(int startData, int endData, int newWeight);

    void removeNode(int data);
    void removeEdge(int startData, int endData);

    vector<int> solveTSP(int startNodeData);
    void tspHelper(int currentNodeData, unordered_set<int>& visited, vector<int>& currentPath, int currentCost, int& bestCost, vector<int>& bestPath, int startNodeData);
};
class QtGraphs : public QMainWindow
{
    Q_OBJECT
public:
    QtGraphs(QWidget* parent = nullptr);
    ~QtGraphs();
    Graph graph;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::QtGraphs ui;
    Node* m_selectedNode;
    bool m_nodeSelected;
    void printAdjacencyTable(const Graph& graph)
    {
        for (const auto& pair : graph.nodes_map)
        {
            int nodeData = pair.first;
            Node* node = pair.second;
            std::cout << "Vertex " << nodeData << ": ";
            std::unordered_set<int> printedNodes;
            for (Edge* edge : node->edges_to_node)
            {
                if (printedNodes.find(edge->to->data) == printedNodes.end())
                {
                    std::cout << "[" << edge->to->data << ", " << edge->weight << "] ";
                    printedNodes.insert(edge->to->data);
                }
            }
            std::cout << std::endl;
        }
    }
    bool sel = 0;
    Node* sNode;

    void on_pushButton_AddNode_clicked();
    void on_pushButton_AddEdge_clicked();
    void on_pushButton_DeleteNode_clicked();
    void on_pushButton_DeleteEdge_clicked();
    void on_pushButton_ObxodInDepth_clicked();
    void on_pushButton_AlgoritmDijkstra_clicked();
    void on_pushButton_ObxodInWidht_clicked();
    void on_pushButton_ZagotovlenGraph_clicked();
    void on_pushButton_randGraph_clicked();
    void on_pushButton_UpdateEdge_clicked();
    void on_pushButton_Tablica_clicked();
    void on_pushButton_CLEAR_clicked();
};
