#include <iostream>

//de implementat cel mai mare din stanga element pentru fiecare element
//

struct Node{
    int value;
    Node* next;
    Node* prev;
    Node();
    Node(int a);
    int getVal()const;
    void setVal(const int);
};

class List
{
    public:
    Node* start;
    Node* finish;
public:
    List();
    void pushBack(Node*);
    void pop();
    Node& getLast()const;
    void createNewNode(const int value);
    void insertNThposition(const int post, Node* nodeToInsert);
};



int main()
{
    List lista;
    Node* newNode = new Node(120);
    lista.createNewNode(123);
    lista.createNewNode(1241);
    lista.createNewNode(420);
    lista.createNewNode(12301);
    lista.createNewNode(12318);
    lista.createNewNode(381);

    lista.insertNThposition(5, newNode);
    std::cout << lista.start->next->getVal();


    return 0;
}

Node::Node()
{
    this->value = -1;
    this->prev = nullptr;
    this->next = nullptr;
}

Node::Node(const int newVal): value(newVal)
{
    this->prev = nullptr;
    this->next = nullptr;
}

int Node::getVal() const
{
    return this->value;
}

void Node::setVal(const int newVal)
{
    this->value = newVal;
}


List::List()
{
    this->start = nullptr;
    this->finish = nullptr;
}

void List::pushBack(Node* newNode)
{
    if(start == nullptr && finish == nullptr){
        start = newNode;
        finish = newNode;
    }
    else{
        Node* aux = finish;
        finish->next = newNode;
        newNode->prev = aux;
        newNode->next = nullptr;
        finish = newNode;
    }
}

void List::pop()
{
    Node* aux = finish;
    this->finish = finish->prev;
    finish->next = nullptr;
    delete aux;
}

Node& List::getLast() const
{
    return *finish;
}

void List::createNewNode(const int val)
{
    Node* newNode = new Node(val);
    this->pushBack(newNode);
}

void List::insertNThposition(const int n, Node* node)
{
    Node* currentNode = start;
    for(int i = 0; i < n; i++){
        currentNode = currentNode->next;
    }
    Node* leftNode = currentNode->prev;
    Node* rightNode = currentNode->next;
    node->prev = leftNode;
    node->next = rightNode;
    leftNode->next = node;
    rightNode->prev = node;
}
