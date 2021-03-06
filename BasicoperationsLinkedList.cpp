#include<iostream>
using namespace std; 
class node 
{
	public:
		int data;          // data = entered value 
		node* next;        // next = pointer 
		// CONSTRUCTOR 	IS CREATED 
	node (int d)
	{
		data = d;            // The input data 
		next = NULL;         // The adress value 
	}
}; 
// Inserting at the head 
void insertAtHead(node* &head , int data)
{
	node *n = new node(data);
	n -> next = head;
	head = n;
}
//Counting the length of the linked list 
int length(node *head)
{
	int count = 0;
	
	while(head != NULL)
	{
		head = head -> next;
		count +=1;
	}
	return count;
}
//Inserting the node at the Tail 
void insertatTail(node* &head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
        return;
	}
	node *tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	node* n = new node(data);
        tail->next = n;
	return;
	
}
//Inserting the node at the middle 
void insertIntheMiddle(node* &head , int data , int p)
{
	if(head == NULL || p == 0)
	{
		insertAtHead(head,data);
		
	}
	else if(p > length(head))
	{
		insertatTail(head,data);
	}
	else
	{
		//Insert in the middle 
		//Take p-1 jumps 
		int jump = 1;
		node*temp = head;
		while(jump<=p-1)
		{
			temp = temp -> next;
			jump +=1; 
		}
		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
	return;
}
//Deleting the node at the head 
void deleteathead(node*&head)
{
	if(head == NULL)
	{
		return; // Means node doesnt exist 
	}
	node *temp = head ; //Storing head in temproray pointer 
	head = head -> next ; // Making head point to the next node 
	delete temp;
	return;
}
//Deleting the node at the tail 
void deleteattail(node*&head)
{
	node *prev = NULL;
	node *temp = head; 
	while(temp -> next != NULL)
	{
		prev = temp;
		temp = temp -> next;
	}
	delete temp;
	prev->next = NULL;
	return;
}
//Deleting using the middle 
void deleteatmiddle(node*&head, int pos)
{
	int i = 1; 
	node*fast = head;
	while (i<pos-1)
	{
		fast = fast->next;
		i++;
	}
	node *prev = fast -> next;
	fast->next = prev -> next;
	delete prev;
	return; 	
}
//Searching using recursion 
bool searchin(node *&head , int key)
{
	if(head == NULL)
	{
		return false;
	}
	if(head -> data == key)
	{
		return true;
	}
	else 
	{
		return searchin(head->next , key);
	}
}
//Searching using iteration
bool searchIterative(node *&head , int key)
{
	while(head !=NULL)
	{
		if(head->data == key)
		{
			return true;
		}
		head = head -> next;
	}
	return false; 
}
// Building the linked list until the node is -1 
void buildList(node*&head)
{
	int data;
	cin>>data; 
	while(data!=-1)
	{
		insertatTail(head,data);
		cin>>data;
	}
}
//Reversing the Linked List 
void reverse(node *&head)
{
	node *C = head ;  //Current Pointer 
	node *P = NULL ; //Previous Pointer 
	node *N; 
	while(C!=NULL)
	{
		//Save the next node 
		N = C -> next ; 
		// Make the current node point to prev
		C -> next = P ; 
		//just update prev and current 
		P = C; 
		C = N;
	}
	head = P; 
	return;
}
//Reversing the Linked List using recursion 
node *reverseRec(node *head)
{
	//Base Case
	if(head -> next == NULL || head == NULL)
	{
		return head; 
	}
	//Rec case 
	node *smallhead = reverseRec(head->next);
	node *C = head; 
	C->next->next = C; 
	C->next = NULL; 
	return smallhead; 	
}
void print(node *&head)
{
    node *temp = head;
    while(temp!= NULL)
    {
         cout<<temp->data<<"->"; //temp->data is used to access the data in the linked list 
         temp= temp -> next;  // Next is used to move to next variable 
     }
}     
int main()
{
	node *head = NULL;
	//Creating a list 
	buildList(head);
	//Inserting the element at the head of the linked list 
	insertAtHead(head,5);
	//Inserting the second element at the head of linked List 
	insertAtHead(head,4);
	//Inserting the third element at the head of the Linked List 
	insertAtHead(head,3);
	//Inserting the element at the tail of the Linked List 
	insertatTail(head,6);
	//Inserting the element at the middle of the Linked List 
	insertIntheMiddle(head,2,8);
	//Deleting at the Tail 
	deleteattail(head);
	//Deleting at the Head 
	deleteathead(head);
	//Deleting at the Middle 
	deleteatmiddle(head,2);
	//To pass in overloaded function 
	node*head2 = NULL; 
    	//Using operator overloading this would return the list; otherwise would have return the adress 
    	cin>>head>>head2;  
    	cout<<head<<endl<<head2;
    	// Reversing using iteration 
    	reverse(head);
    	//Reversing using Recursion 
    	head = reverseRec(NULL);
    	//Printing the value of head 
    	print(head);
    	//Syntax to search the element in the list 
	if (searchin(head,4))
	{
		cout<<"Element found"<<endl;
	}
	else 
	{
		cout<<"Element not found"<<endl;
	}
	//Syntax to search element using iteration  
	if (searchIterative(head,14))
	{
		cout<<"Element found"<<endl;
	}
	else 
	{
		cout<<"element not found"<<endl;
	}
	return 0;
}
