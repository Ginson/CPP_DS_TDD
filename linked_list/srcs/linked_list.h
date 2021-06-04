#include<iostream>

struct linked_list_node
{
    int data;
    linked_list_node *node;

    linked_list_node(int val)
    {
        data = val;
        node = nullptr;
    }
};

class LinkedList
{
    public:
    LinkedList();
    ~LinkedList();

    void Push_Front(int val);
    void Push_Rear(int val);
    void Push_AtPosition(int val, int position);

    void Pop_Front();
    void Pop_Rear();
    void Pop_AtPosition(int position);

    linked_list_node* GetList() const;
    int GetListSize() const;
    
    void AppendList(linked_list_node* node);
    void ReverseList();
    //Try using a function pointer to sort in asc or desc
    void Sort();
    bool Find(int val);

    private:
    linked_list_node* node{nullptr};
};