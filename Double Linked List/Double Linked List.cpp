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

	/*insert a Node Between Two Nodes in the List*/
	Node* current = START;														//step 1.a
	Node* previous = NULL;														//step 1.b
	while (current->next != NULL && current->next->noMhs < nim)					//step 1.c
	{
		previous = current;														//step 1.d
		current = current->next;												//step 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;												//step 4
	newNode->prev = current;													//step 5
	if (current->next != NULL)
		current->next->prev = newNode;											//step 6
	current->next = newNode;													//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;															//step 1.a
	*current = START;															//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {					//step 1.c
		*previous = *current;													//step 1.d
		*current = (*current)->next;											//step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;											//step 2
	if (previous != NULL)
		previous->next = current->next;											//step 3
	else
		START = current->next;
	delete current;																//step 4
	return true;
}

bool DoubleLinkedList :: listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList :: traverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecord in Ascending Order of Roll Number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecord in Ascending Order of Roll Number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a Record to the List" << endl;
			cout << "2. Delete a Record from the List" << endl;
			cout << "3. View All Record in the Ascending order of Roll Number" << endl;
			cout << "4. View All Record in the Descending order of Roll Number" << endl;
			cout << "5. Search for a Record in the List" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your Choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				if (obj.listEmpty()) {
					cout << "\nList is Empty" << endl;
					break;
				}
				cout << "\nEnter the roll number of the student whose record is to be deleted: ";
				int rollNo;
				cin >> rollNo;
				cout << endl;
				if (obj.deleteNode(rollNo) == false)
					cout << "Record not Found" << endl;
				else
					cout << "Record with Roll number" << rollNo << "Deleted" << endl;
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case'5':
				if (obj.listEmpty() == true) {
					cout << "\nList is Empty" << endl;
					break;
				}
				Node* prev, * curr;
				prev = curr = NULL;
				cout << "\nEnter the roll number of the student whose record you want to search: ";
				int num;
				cin >> num;
				if (obj.search(num, &prev, &curr) == false)
					cout << "\nRecord not Found" << endl;
				else {
					cout << "\nRecord Found" << endl;
					cout << "\nRoll Number: " << curr->noMhs << endl;
					cout << "\nName: " << curr->name << endl;
				}
				break;
			case '6':
				return 0;
			default:
				cout << "Invalid Option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the Values Entered." << endl;
		}
	}
}
