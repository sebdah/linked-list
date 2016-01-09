typedef int T;

class Node
{
  private:
    T data;
    Node* next;
    Node* prev;

  public:
    Node(const T&);

    T getData();
    Node* getNext();
    Node* getPrev();
    bool hasNext();
    bool hasPrev();
    void setData(const T&);
    void setNext(Node*);
    void setPrev(Node*);
};
