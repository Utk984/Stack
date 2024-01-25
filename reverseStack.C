#include <iostream>
using namespace std;

class Node {
  public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Stack {
	Node* head;

public:
	Stack() { head = NULL; }
	void push(int);
	void print();
	void pop();
  void top();
  void reverse();
};

void Stack::pop()
{
	Node *temp1 = head;

	if (head == NULL) {
		cout << "Stack empty." << endl;
		return;
	}

	while (temp1->next->next != NULL) {
		temp1 = temp1->next;
	}

		delete temp1->next;
    temp1->next = NULL;
}

void Stack::push(int data)
{
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void Stack::print()
{
	Node* temp;
  temp = head;

	if (temp == NULL) {
		cout << "Stack empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
  cout << endl;
}
void Stack::reverse()
{
	Node *temp = head->next,*temp2;

	if(head==NULL)
	{
			cout << "List empty" << endl;
			return;
	}
	head->next = NULL;
	while(temp!=NULL)
	{
			temp2 = temp->next;
			temp->next = head;
			head = temp;
			temp = temp2;
	}
}

void Stack::top()
{
	Node* temp = head; 

	while (temp->next != NULL) {
		temp = temp->next;
	}
  cout << "Top element: " << temp->data << endl;
}

int main()
{
	Stack stack;
	
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  
  stack.top();
  cout << "\nStack: " << endl;
  stack.print();
  cout << "\nReverse: " << endl;
  stack.reverse();
  stack.print();

  stack.pop();
  stack.pop();

  cout << "\nAfter popping: " << endl;
  stack.top();
  cout << "\nStack: " << endl;
  stack.print();
}
