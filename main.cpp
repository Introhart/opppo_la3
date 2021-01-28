#include <iostream>



class Plant
{
protected:
    std::string name;
public:
    virtual void setName(std::string _name)
    {
        name = _name;
    }

    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getType()
    {
        return "plant";
    }
};


class Tree : public Plant
{
    std::string name;
public:
    Tree(std::string _name) : name(_name) {}
    ~Tree(){}

    void setName(std::string _name) override
    {
        _name = name;
    }

    std::string getName() override
    {
        return name;
    }

    std::string getType() override
    {
        return "tree";
    }
};


class Bush : public Plant
{
    std::string name;
public:
    Bush(std::string _name) : name(_name) {}
    ~Bush(){}

    void setName(std::string _name) override
    {
        _name = name;
    }

    std::string getName() override
    {
        return name;
    }

    std::string getType() override
    {
        return "bush";
    }
};

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
            head = tail = nodeNew;
            head->ptr = tail;
            tail->ptr = head;
        }
        else
        {
            tail->ptr = nodeNew;
            nodeNew->ptr = head;
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
        return Iterator<T>(tail);
    }
};






int main()
{
    Plant *t1 = new Tree("Tree_1");
    Plant *t2 = new Tree("Tree_2");
    Plant *b1 = new Bush("Bush_1");
    Plant *b2 = new Bush("Bush_2");

    List<Plant> *list = new List<Plant>();
    list->append(*t1);
    list->append(*t2);
    list->append(*b1);
    list->append(*b2);

    for(auto it = list->begin(); it != list->end(); ++it)
    {
        std::cout << (*it).getName() << std::endl;
    }
    
    return 0;
}