//201610674 컴퓨터공학부 이영훈
#include "Node.h"

class LinkedQueue {
	Node* front;
	Node* rear;
public:
	LinkedQueue() : front(NULL), rear(NULL) {	}
	~LinkedQueue() {while(!isEmpty()) delete dequeue();	}
	bool isEmpty() {return front == NULL;	}
	
	void enqueue (Node *p) {
		if(isEmpty()) front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}
	
	Node* dequeue() {
		if (isEmpty()) return NULL;
		Node* p =front;
		front = front->getLink();
		if(front==NULL) rear=NULL;
		return p;
	}
	Node* peek() {return front;	}
	void display() {
		printf("[큐 내용] : ");
		for (Node* p = front ; p!=NULL ; p=p->getLink())
			p->display();
		printf("\n");
	}
};
