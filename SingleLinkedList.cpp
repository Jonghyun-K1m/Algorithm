
#include <iostream>

using namespace std;

class List {
private:
	struct node {
		int data;
		node* next;
	};
	node* head = NULL;
	node* curr = NULL;

	int count = 0;

public:
	void addData(int num);
	void printList();
	void delData(int num);
	void length();
	void moveLastToHead();
	void swapNodes();

	void sortNodes();
	void reverseNode();
};

void List::reverseNode() {
	
	node* n;
	node* p;
	node* q;
	n = NULL;
	q = NULL;
	p = head; 
	while (p != NULL) {	//p keeps going q get reversing 
		n = q;		
		q = p;
		p = p->next;
		q->next = n;		
	}

	head = q;
}


void List::moveLastToHead() {
	node* prev = NULL;
	node* ttemp = NULL;
	curr = head;
	while (curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	ttemp = curr;	//transfer curr to temp
	ttemp->next = head;	//set ttemp.next to head
	head = ttemp;	//now head include curr's info,address
	prev->next = NULL;	//delete curr 
}

void List::swapNodes(){
	node *prev = head;		//set pre to temp
	node *temp = prev->next;
	prev->next = temp->next;
	temp->next = prev;

	head = temp;
	temp = prev->next;

	while (temp != NULL && temp->next != NULL) {	//swapping
		node *post = temp->next;
		prev->next = post;
		temp->next = post->next;
		post->next = temp;
		prev = temp;
		temp = prev->next;
	}
	
}




void List::sortNodes() {    //bubble sorting

	node*i = head;
	node*j = head;
	int temp;

	while (i->next != NULL) {
		i = i->next;		
		while (j->next != NULL) {
			if (i->data < j->data) {    
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
			j = j->next;
		}
		j = head;		
		
	}
}




void List::addData(int num) {
	count++;
	if (head == NULL) {
		head = new node();
		head->data = num;
		head->next = NULL;
		return;
	}

	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	if (curr->next == NULL) {
		node* n = new node();
		n->data = num;
		n->next = NULL;
		curr->next = n;
		return;
	}
}

void List::printList() {
	if (head != NULL) {
		curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	else
		cout << "List is empty";
	cout << endl;
}

void List::delData(int num) {
	if (head != NULL) {
		if (head->data == num) {
			count--;
			node* del = head;
			head = head->next;
			delete del;
			return;
		}
		curr = head;
		node* prev = NULL; //초기화오류
		while (curr->next != NULL && curr->data != num) {
			prev = curr;
			curr = curr->next;
		}
		if (curr->data == num) {
			count--;
			node* del = curr;
			prev->next = curr->next;
			delete del;
		}
		else {
			cout << "The value not found\n";
		}
	}
	else
		cout << "List is empty\n";
}

void List::length() {
	cout << count;
}

int main() {

	List obj;
	int num;
	char x;

	cin >> x;

	while (x != 'e') {
		switch (x) {
		case'i':
			cin >> num;
			obj.addData(num);
			//obj.sortNodes();
			break;
		case'p':
			obj.printList();
			break;
		case'd':
			cin >> num;
			obj.delData(num);
			break;
		case'l':
			obj.length();
			break;
		case'm':
			obj.moveLastToHead();
			break;
		case's':
			obj.swapNodes();
			break;
		case'r':
			obj.reverseNode();
			break;
		}

		cin >> x;
	}

	return 0;
}
