#include "linked_list.h"

LinkedList::LinkedList()
{
    
}

LinkedList::~LinkedList()
{

}
void LinkedList::Push_Front(int val)
{
    linked_list_node *new_node = new linked_list_node(val);
    if(node_ == nullptr)
    {
        node_ = new_node;
    }
    else
    {
        new_node->next = node_;
        node_ = new_node;
    }

    node_count_++;
}

void LinkedList::Push_AtPosition(int val, int position)
{
    linked_list_node *new_node = new linked_list_node(val);
    if(node_ == nullptr)
    {
        node_ = new_node;
    }
    else
    {
        auto tmp_node = node_;
        int idx{0};
        while(idx < position)
        {
            idx++;
            tmp_node = tmp_node->next;
        }
        new_node->next =  tmp_node->next;
        tmp_node->next = new_node;
    }

    node_count_++;
}

void LinkedList::Push_Rear(int val)
{
    linked_list_node *new_node = new linked_list_node(val);
    if(node_ == nullptr)
    {
        node_ = new_node;
    }
    else
    {
        linked_list_node *tmp_head = node_;
        while (tmp_head->next != nullptr)
        {
            tmp_head = tmp_head->next;
        }
        tmp_head->next = new_node;
    }

    node_count_++;
}    

void LinkedList::Pop_Front()
{
    auto tmp_head = node_;
    node_ = tmp_head->next;
    delete tmp_head;
    node_count_--;
}

void LinkedList::Pop_AtPosition(int position)
{
    auto tmp_head = node_;
    auto prev_node = node_;
    int idx{0};
    while(idx < position)
    {
        prev_node = tmp_head;
        tmp_head = tmp_head->next;
        idx++;
    }

    prev_node->next = tmp_head->next;
    delete tmp_head;
    node_count_--;
}

void LinkedList::Pop_Rear()
{
    auto tmp_head = node_;
    auto prev_node = node_;
    while(tmp_head->next != nullptr)
    {
        prev_node = tmp_head;
        tmp_head = tmp_head->next;
    }
    
    delete tmp_head;
    prev_node->next = nullptr;
    
}

void LinkedList::DisplayList() const
{
    auto tmp = node_;
    while(tmp != nullptr)
    {
        std::cout<<tmp->data<<std::endl;
        tmp = tmp->next;
    }

}
