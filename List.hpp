#include "Node.hpp"

class List
{
  private:
    bool debug;
    Node* first;
    Node* last;

  public:
    List();
    ~List();

    void empty();
    Node* getFirst();
    Node* getLast();
    bool hasFirst();
    bool hasLast();
    void insertAfter(int, const T& data);
    void insertBefore(int, const T& data);
    Node popFirst();
    Node popLast();
    void print();
    void printNode(Node*);
    void pushFirst(const T& data);
    void pushLast(const T& data);
    void setDebug(bool);
    void setFirst(Node*);
    void setLast(Node*);
};
