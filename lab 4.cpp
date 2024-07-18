#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node * next;
		
	node(int value){
		data=value;
		next =NULL;
		
	}
};
class linklist{
	private :
		node* head;
		public:
			linklist(){
				head=NULL;
			}
			void insert(int value){
				node*newnode=new node(value);
				if(head==NULL){
					head=newnode;		
				}
				else{
				node*temp=head;	
				while(temp->next != NULL){
					temp=temp->next;
				}
				temp->next=newnode;
				}
			}
			void insert_start(int value){
					node*newnode=new node(value);
				if(head==NULL){
					head=newnode;		
				}
				else{
				
				newnode->next=head;
				head=newnode;
				}
			}
			void delete1(){
				node * temp=head;
//				node * temp2=head-next;
//				head=temp2;
				head=temp->next;
			}
			
			void display(){
				node*temp=head;
				while(temp!= NULL){
					cout<<temp->data<<",";
					temp=temp->next;
				}
				cout<<endl;
			}
};


int main(){
	linklist mylist;
	for(int i=10;i<=100;i+=10){
		mylist.insert(i);
	}
	mylist.insert_start(11);
	mylist.display();
	cout<<endl;
	mylist.delete1();
	
	mylist.display();
}
