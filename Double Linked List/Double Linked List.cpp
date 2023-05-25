#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the Roll Number of the Student: ";
	cin >> nim;
	cout << "\nEnter the name of the Student: ";
	cin >> nm;
	Node* newNode = new Node();													//step 1
	newNode->noMhs = nim;														//step 2
	newNode->name = nm;															//step 2

	/*insert a node in the beginning of a doubly*/								//step 3
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;													//step 3
		if (START != NULL)
			START->prev = newNode;												//step 4
		newNode->prev = NULL;													//step 5
		START = newNode;														//step 6
		return;
	}
}




int main() {

}
