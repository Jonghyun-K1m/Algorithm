/* 
  13011065 kim
   the algoritm to fix out Josephus problem
   I used dummy node in head, so list have conditions to pass head node
   I made list to jump to the next node ,when it meets head node
   
*/


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
	int length();
	void moveLastToHead();
	void swapNodes();
	void sortNodes();
	void reverseNode();
	int Joseph(int num);
	void init(int num);
};
int List::Joseph(int num) {     
	int returned = 0;
	node* prev = NULL;
	node* temp = NULL;
	int run = 1;
	curr = head->next;
	//cout << curr->data << endl;
	while (count >1) {
		
		//cout << "run";
		for (run = 1; run <= num; run++) {
			//if (prev==head ||curr == head || curr->next==head)curr = curr->next;
				prev = curr;
				if(curr->next!=head)curr = curr->next;
				else {
					curr = curr->next->next;
					//run--;
					//cout << "head지남" << endl;
				}
				//cout << "PREV::"<<prev->data <<" "<<curr->data<< endl;

			}
			//cout << "mid";
			count--;
			
			node* del = curr;
			prev->next = curr->next;
			//cout << "prev::::::::::::" << prev->data << endl;
			//cout << "왼쪽오른쪽::::::::::::" << prev->next->data << endl;
			//cout << "나가는곳::::::::::::" << curr->data << endl;
			returned = prev->data;
			curr = prev;
			delete del;
			
			prev = curr;
			if (curr->next != head)curr = curr->next;
			else {
				curr = curr->next->next;
				//cout << "head지남" << endl;
			}
			//cout << "done";
		}
	std::cout <<returned << endl;
	return returned;
}
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
void List::swapNodes() {
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
	if (count==1) {
		head = new node();
		head->data = NULL;
		head->next = NULL;

		node* n = new node();
		n->data = num;
		n->next = head;
		head->next = n;
		return;
	}

	curr = head;
	while (curr->next != head) {
		curr = curr->next;
	}

	if (curr->next == head) {
		node* n = new node();
		n->data = num;
		n->next = head;
		curr->next = n;
		return;
	}
}
void List::init(int num) {
	count = 1;
	head = new node();
	head->data = NULL;
	head->next = NULL;

	node* n = new node();
	n->data = num;
	n->next = head;
	head->next = n;
	return;
}
void List::printList() {  
	int hcount = 0;
	if (count != 0) {
		curr = head->next;
		while (curr != NULL) {
			//if (curr == head)hcount++;
			//sif (hcount >= 2)break;
			std::cout << curr->data << " ";
			if (curr->next == head)break;
			curr = curr->next;
		}
	}
	else
		std::cout << "List is empty";
	std::cout << endl;
//	cout << hcount << endl;
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
			std::cout << "The value not found\n";
		}
	}
	else
		std::cout << "List is empty\n";
}

int List::length() {
	std::cout << count;
	return count;
}

int main() {

	List obj;
	int num;
	char x;
	int size, rcount = 0;
	cin >> x;
	

	while (x != 'e') {
		switch (x) {
		case'j':
			cin >> num;
			size=obj.Joseph(num);
			obj.init(size);
			//size = obj.length();
			//obj.addData(size);
			break;

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
