#include "plants_test.h"


template <typename T>
struct Node
{
    T* value;
    Node<T>* ptr;
public:

    T& operator* ()
    {
        return *value;
    } 
};


template <typename T>
class Iterator
{
    Node<T>* curNode;
public:
    Iterator(Node<T>* node) : curNode(node) {}

    T& operator* ()
    {
        return **curNode;
    }

    Iterator<T>& operator++()
    {
        curNode = curNode->ptr;
        return *this;
    }

    bool operator!= (Iterator const& it)
    {
        return curNode->value != it.curNode->value;
    }

    bool operator== (const Iterator& it)
    {
        return curNode->value == it.curNode->value;;
    }
};




template <typename T>
class List
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Node<T>* linkNode = nullptr;
    unsigned int size = 0;

public:

    List() {}
    ~List() {}

    void append(T& value)
    {
        Node<T>* nodeNew = new Node<T>();
        nodeNew->value = &value;

        if(size == 0)
        {
            linkNode = new Node<T>();

            head = tail = nodeNew;
            head->ptr = tail;
            tail->ptr = linkNode;
            linkNode->ptr = head;
        }
        else
        {
            tail->ptr = nodeNew;
            nodeNew->ptr = linkNode;
            tail = nodeNew;
        }
        size++;
    }


    Iterator<T> begin()
    {
        return Iterator<T>(head);
    }

    Iterator<T> end()
    {
        return Iterator<T>(linkNode);
    }
};