#include "Node.hpp"

class List
{
  private:
    Node* first;
    Node* last;

  public:
    List();

    void empty();
    Node* getFirst();
    Node* getLast();
    bool hasFirst();
    bool hasLast();
    void setFirst(Node*);
    void setLast(Node*);
    Node* popFirst();
    Node* popLast();
    void pushFirst(const T& data);
    void pushLast(const T& data);
};
