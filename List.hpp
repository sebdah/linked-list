#include "Node.hpp"

class List
{
  private:
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
    void pushFirst(const T& data);
    void pushLast(const T& data);
    void setFirst(Node*);
    void setLast(Node*);
};
