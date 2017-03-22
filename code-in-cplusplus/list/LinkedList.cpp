#include <iostream>
#include "LinkedList.hpp"

using namespace std;

namespace mylistns {
    
    ListNode::ListNode(int data = 0) {
        //cout << "Constructing ListNode..." << endl;
        this->data = data;
        this->next = NULL;
    }
    
    ListNode::~ListNode() {
        //cout << "Destructing ListNode..." << endl;
    }

    LinkedList::LinkedList() {
        //cout << "Constructing LinkedList..." << endl;
        head = new ListNode();
        last = head;
        num_elements = 0;
    }
    
    LinkedList::~LinkedList() {
        //cout << "Destructing LinkedList..." << endl;
        while (head != NULL) {
            head = head->next;
            delete head;
        }
    }
    
    //O(n)
    int LinkedList::get(int index) {
        if (index < 0 || index >= num_elements)
            return (int) NULL;
        ListNode* current;
        for (current = head->next; index > 0; current = current->next, --index);
        return current->data;
    }
    
    //O(1)
    void LinkedList::add(int e) {
        last->next = new ListNode(e);
        last = last->next;
        ++num_elements;
    }
    
    //O(n)
    void LinkedList::display() {
        ListNode* current;
        for (current = head->next; current != NULL; current = current->next) {
            cout << current->data << endl;
        }
    }
    
    //O(1)
    int LinkedList::size() {
        return num_elements;
    }
    
}
