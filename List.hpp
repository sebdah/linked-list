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
    Node* popFirst();
    Node* popLast();
    void pushFirst(const T& data);
    void pushLast(const T& data);
    void setFirst(Node*);
    void setLast(Node*);
};
