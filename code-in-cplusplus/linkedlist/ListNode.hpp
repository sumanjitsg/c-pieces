#ifndef LISTNODE_H
#define LISTNODE_H

namespace mylinkedlist {
    
	class ListNode {
		public:
			int data;
			ListNode* next;
            
			ListNode(int e) {
				this->data = e;
				this->next = NULL;
			}

			ListNode() {
				this->next = NULL;
			}
            
            friend void addFirst(ListNode* head, int e);
            friend void deleteList(ListNode* head);
            friend void displayList(ListNode* head);
	};

}
#endif
