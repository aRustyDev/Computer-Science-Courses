#include "Node.h"
#include "DNode.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Node<string>* head = new Node<string>("Tom");
	Node<string>* john = new Node<string>("john");
	Node<string>* harry = new Node<string>("Harry");
	Node<string>* sam = new Node<string>("Sam");
	
	//constructing the linked list

	Node<string>* tom = head;
	tom->next = john;
	john->next = harry;
	harry->next = sam;

	//traversing a singly-linked list
	Node<string>* current_node = head;
	
	while (current_node != NULL){
		cout << current_node->data;

		if (current_node->next != NULL)
			cout << "==>";

		current_node = current_node->next; //advance the current node
	}

	//insert a node "Smair" before "Sam"

	if (head==NULL)
		throw std::exception("empty list");

	current_node = head; 
	
	while (current_node->next != sam) {
		current_node = current_node->next; //advance the current node
		if (current_node == NULL) // we've reached the end, and didn't find Sam
			throw std::exception("Node doesn't exist");
	}

	Node<string>* samir = new Node<string>("Smair", current_node->next);
	current_node->next = samir;
	

	//delete a node before "sam"
	if (head == NULL || head->next == NULL)
		throw std::exception("empty list or a list that contains one node");
	
	current_node = head; 
	
	while (current_node->next != NULL){
		if (current_node->next->next == sam){
			Node<string>* to_be_deleted = current_node->next; //the node to be deleted
			current_node->next = current_node->next->next;
			delete to_be_deleted;
			break;
		}
		current_node = current_node->next;
	}







	//insert a node after harry
	Node<string>* bob = new Node<string>("Bob");
	bob->next = harry->next;
	harry->next = bob;

	//delete a node after Tom
	Node<string>* ptr = tom->next;
	tom->next = tom->next->next;
	delete ptr;


	Node<string>* head_2 = new Node<string>("Tom");
	head_2->next = new Node<string>("john");
	head_2->next->next = new Node<string>("Harry");
	head_2->next->next->next = new Node<string>("Sam");
	
	Node<string>* head_3 = new Node<string>("Sam");
	head_3 = new Node<string>("Harry", head);
	head_3 = new Node<string>("john", head);
	head_3 = new Node<string>("Tom", head);

	//building a doubly-linked list

	DNode<string>* john_d = new DNode<string>("John");
	DNode<string>* harry_d = new DNode<string>("Harry");
	DNode<string>* sam_d = new DNode<string>("Sam");

	john_d->next = harry_d;
	harry_d->prev = john_d;
	harry_d->next = sam_d;
	sam_d->prev = harry_d;

	//inserting a node ("Sharon") before "Sam"

	DNode<string>* sharon_d = new DNode<string>("Sharon");
	sharon_d->next = sam_d; // step 1
	sharon_d->prev = sam_d->prev; //step 2
	
	
	//link old predecessor
	sam_d->prev->next = sharon_d; //step 3
	//link to new predecessor
	sam_d->prev = sharon_d; //step 4

	//deleting node "Harry"
	harry_d->prev->next = harry_d->next; //step 1
	harry_d->next->prev = harry_d->prev; // step 2
	
	
	delete harry_d;

	
	/*another way of doing it
	sam_d->prev->next = sharon_d;
	sharon_d->prev = sam_d->prev;

	sam_d->prev = sharon_d;
	sharon_d->next = sam_d;*/

	return 0;
}

