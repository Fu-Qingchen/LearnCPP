// 1. 用邻接表实现图的数据结构
//  1.1 实现栈 OK
//  1.2 实现节点 OK
//  1.3 实现图 OK
// 2. 用DFS实现这个题目
// 3. 用拓扑排序实现这个题目

#include<iostream>
using namespace std;

struct Vertex;

struct Edge{
    Vertex *fromVertex = nullptr, *toVertex = nullptr;
    Edge *next = nullptr;
    Edge(Vertex *fromData = nullptr, Vertex *toData = nullptr, Edge *nextData = nullptr)
        :fromVertex(fromData), toVertex(toData), next(nextData){}
};

struct Vertex{
    int id = -1;
    int inDegree = 0;
    Edge *firstEdge = nullptr;  // firstChild-brother
    int flag = -1;
    Vertex() {}
    Vertex(const int i):id(i) {}
    ~Vertex(){ while (firstEdge != nullptr){
        Edge *temp = firstEdge;
        firstEdge = firstEdge->next;
        delete temp;
    }}
    void addEdge(Vertex * nextVertex){
        Edge *newEdge = new Edge(this, nextVertex, firstEdge);
        nextVertex->inDegree++;
        firstEdge = newEdge;
    }
};

template <typename T>
class Stack{
private:
    int size = 0;
    T *data = nullptr;
public:
    Stack(const int capacity){ data = new T[capacity]; }
    ~Stack(){ delete [] data; }
    void push(const T value){ data[size++] = value; }
    T pop(){ return data[--size]; } 
    T top()const{ return data[size - 1]; }
    int getSize()const{ return size; }
};

class Graph{
private:
    int size = 0;
    Vertex *vertexlist = nullptr;
    void resetState(){ 
        for (int i = 0; i < size; i++){ 
            // vertexlist[i].flag = -1;
            Edge *tempEdge = vertexlist[i].firstEdge;
            while (tempEdge != nullptr){
                tempEdge->toVertex->inDegree++;
                tempEdge = tempEdge->next;
            }
        }
    }
public:
    void topologicalSort(int *&);
    int getMaxPath(int *&);
    Graph(){}
    Graph(int v_num):size(v_num){ initGraph(v_num); }
    ~Graph(){ delete [] vertexlist; }
    void initGraph(const int v_num){
        size = v_num;
        vertexlist = new Vertex[v_num];
        for (int i = 0; i < v_num; ++i){ vertexlist[i] = Vertex(i + 1);}
    }
    void addEdge(const int from_id, const int to_id){ vertexlist[from_id - 1].addEdge(&vertexlist[to_id - 1]); }
    Edge *& firstEdge(const int ver_id)const{ return vertexlist[ver_id - 1].firstEdge; }
    Edge *& nextEdge(Edge *& cur_Edge)const{ return cur_Edge->next; } 
    int getIdByEdge(Edge *& edge)const{ return edge->toVertex->id; }
};

int Graph::getMaxPath(int *& sortlist){
    topologicalSort(sortlist);
    int pathlength = 1;
    for (int i = 0; i < size; i++){
        Edge *temp = vertexlist[sortlist[i]].firstEdge;
        if (temp == nullptr){ continue; }
        while (temp != nullptr){
            int thismax = temp->fromVertex->flag + 1;
            temp->toVertex->flag = thismax > temp->toVertex->flag ? thismax : temp->toVertex->flag;
            pathlength = thismax > pathlength ? thismax : pathlength;
            temp = temp->next;
        }
    }
    return pathlength;
}

void Graph::topologicalSort(int *& sortlist){
    int i = 0;
    Stack<int> tempStack(size);
    for (int i = 0; i < size; i++){ if (vertexlist[i].inDegree == 0){ tempStack.push(i); vertexlist[i].flag = 1; }}
    while (tempStack.getSize() != 0){
        int temp = tempStack.pop();
        sortlist[i++] = temp;
        Edge *tempEdge = vertexlist[temp].firstEdge;
        while (tempEdge != nullptr){ 
            tempEdge->toVertex->inDegree--;
            if (tempEdge->toVertex->inDegree == 0){ tempStack.push(tempEdge->toVertex->id - 1);}
            tempEdge = tempEdge->next;
        }
    }
    resetState();
}

int n, m;
Graph graph;
int *topoSort;

void input(){
    int v1, v2;
    cin >> n >> m;
    graph.initGraph(n);
    topoSort = new int[n];
    for (int i = 0; i < m; ++i){
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }
}

int main(){
    input();
    int temp = graph.getMaxPath(topoSort);
    cout << temp;
}