/*
   I used dummy node in head, so list have conditions to pass head node
   I made list to jump to the next node ,when it meets head node
   
   got time limit(loop eroor)
*/


#include <iostream>

using namespace std;

class List {
private:
	struct node {
		int data;
		node* next;
		node* prevv;
	};
	node* head = NULL;
	node* curr = NULL;

	int count = 0;

public:
	void addData(int num);
	void printList();
	void reverseNode();
	void find(int a, int b);
};
void List::find(int a,int b) {
	int ncount = 0;
	int pcount = 0;
	int isexist = 0;
	node* ago = NULL;
	node* bgo = NULL;
	node* prev = NULL; //초기화오류
	if (count < 0) {
		std::cout << "No data" << endl;
		return;
	}

	curr = head->next;
	while (curr->next != NULL) {
		if (curr->data == a || curr->data == b)isexist++;
		curr = curr->next;
		if (curr == head)break;
	}
	if (isexist != 2) {
		std::cout << "No data"<<endl;
		return;
	}
	
		curr = head->next;
		
		while (curr->next != NULL && curr->data != a) {
			//prev = curr;
			curr = curr->next;
			//ncount++;
		}
		ago = curr;
		//cout << "do" << endl;
		/*curr = head->next;
		while (curr->next != NULL && curr->data != b) {
			//prev = curr;
			curr = curr->next;
			//ncount++;

		}
		bgo = curr;  
		*/
		//cout << "f" << endl;
		curr = ago;
		while (curr->next != NULL && curr->data != b) { //Suppose data is Unique
			curr = curr->next;
			//cout << "다음 visit" << curr->data << endl;
			if(curr!=head)ncount++;  //some conditions to solve  when it meets head
		}

		//cout << "g" << endl;

		curr = ago;
		while (curr->prevv != NULL && curr->data != b) { //Suppose data is Unique
			curr = curr->prevv;
			//cout << "전 visit" << curr->data << endl;
			if (curr != head)pcount++; //some conditions to solve  when it meets head
		}
		
		if (ncount > pcount) {  //To count nodes between a and b, it need counter -1 . because we visited destination
			cout <<"There is(are) "<<pcount - 1<<" node(s) between node whit value of "<<a<<" and"<<" node with value of "<<b<< endl;	
		}
		else cout << "There is(are) " << ncount - 1 << " node(s) between node whit value of " << a << " and" << " node with value of " << b << endl;
	
	
		
	return;
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


void List::addData(int num) {
	count++;
	if (count == 1) {
		head = new node();
		head->data = NULL;
		head->next = NULL;
		head->prevv = NULL;
		node* n = new node();
		n->data = num;
		n->next = head;
		n->prevv = head;

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
		n->prevv = curr;
		curr->next = n;
		head->prevv = n;
		return;
	}
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
	/*if (count != 0) {
		curr = head->prevv;
		while (curr != NULL) {
			//if (curr == head)hcount++;
			//sif (hcount >= 2)break;
			std::cout << curr->data << " ";
			if (curr->prevv == head)break;
			curr = curr->prevv;
		}
	}*/
	//	cout << hcount << endl;
}


int main() {

	List obj;
	int num;
	int numb;
	char x;
	int size = 0;
	cin >> x;


	while (x != 'e') {
		switch (x) {
		case'f':
			if (size <= 0)break;
			cin >> num>>numb;
			obj.find(num,numb);
			break;
		case'i':
			cin >> num;
			obj.addData(num);
			size++;
			break;
		case'p':
			obj.printList();
			break;
		case'r':
			obj.reverseNode();
			break;
		}

		cin >> x;
	}

	return 0;
}
