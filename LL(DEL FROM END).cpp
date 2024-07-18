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
		node *temp1,*temp2;
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
			
			void delete_from_end(){
				if (head==NULL){
					exit(0);
					cout<<"@##2";
				}
				else if (head->next==NULL){
					head=NULL;
					cout<<"11111";
				}
				else 
				while(temp2->next!=NULL){
				
				temp1=head->next;
				temp2=temp1->next;
			}
			temp1->next=NULL;
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
	mylist.display();
mylist.delete_from_end();
cout<<endl;
mylist.display();
}