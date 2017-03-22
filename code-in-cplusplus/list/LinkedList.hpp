#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "IList.hpp"

namespace mylistns {
    
    class ListNode {
        public:
            int data;
            ListNode* next;
            ListNode(int e);
            ~ListNode();
    };
    
    class LinkedList: public IList {
            ListNode* head;
            ListNode* last;
            int num_elements;
        public:
            LinkedList();
            ~LinkedList();
            int get(int index);
            void add(int e);
            void display();
            int size();
    };

}

#endif
