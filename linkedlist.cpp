#include <iostream>
#include <cstdlib>

//a basic demonstration of singly-linked lists;
struct node {
    int data;
    node* next;

public:
    node() {
        this->data = 0;
        this->next = NULL;
    }

    node(int arg) {
        this->data = arg;
        this->next = NULL;
    }
};

void addNodeToFront(node **head, int arg) {  
    node *newNode = new node(arg);
	newNode->next = *head;
	*head = newNode;
}

void addNodeToBack(node **head, int arg) {
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    node *newNode = new node(arg);
    current->next = newNode;
    newNode->next = NULL;
}

void addNodeAtIndex(node **head, int arg, int ind) {
    //indexing starts from 0;
    int counter = 0;
    node *current = *head;
    while (counter != ind - 1) {
        current = current->next;
        counter++;
    }
    node *newNode = new node(arg);
    newNode->next = current->next;
    current->next = newNode;
}

void printList(node **head) {
	node *current = *head;
	while (current != NULL)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
	//since the tail node will fail the while test,
	//the value must be printed separately;
}

void delFirstNode(node **head) {
    *head = (*head)->next;
}

void delLastNode(node **head) {
    node *current = *head;
    node *prev = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
}

int main() {
    node *head = NULL;
    addNodeToFront(&head, 1);
    addNodeToFront(&head, 2);
    addNodeToFront(&head, 3);
    addNodeToBack(&head, 4);
    addNodeAtIndex(&head, 5, 2);
    delFirstNode(&head);
    delLastNode(&head);
    printList(&head);
    return 0;
}