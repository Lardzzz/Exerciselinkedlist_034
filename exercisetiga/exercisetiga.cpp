#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //write your answer here
	//deklarasi node input
	int angka;
	cout << "\nMasukkan angka :";
	cin >> angka;

	Node* athalla = LAST;
	Node* lazuardi = nullptr;
	//allocate new memory for the new node
	Node* newNode = new Node();
	if (LAST == nullptr) {
		LAST = newNode;
		LAST->next = LAST;
	}
	else {
		Node* temp = LAST;
		while (temp->next != LAST) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = LAST;
		LAST = newNode;
	}
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //write your answer here
	Node* athalla = LAST;
	Node* lazuardi = nullptr;
	//mencari apakah data terdaftar 
	if (search(int rollno, Node * *previous, Node * *current) == false)
		return false;

	//mark last as null
	if (athalla->next == LAST) {
		LAST == NULL;
	}
	//current successor point of LAST
	if (athalla == LAST && athalla->next == LAST) {
		LAST = athalla;
	}
	else if (athalla == LAST) {
		Node* temp = LAST;
		while (temp->next != LAST) {
			temp = temp->next;
			return 0;
		}
		LAST = LAST->next;
		temp->next = LAST;
	}
	else {
		lazuardi->next = athalla->next;
		return;
	}

	delete athalla;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}