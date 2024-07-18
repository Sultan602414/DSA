#include<iostream>
using namespace std;
class node{
	public:
		int no_of_courses=0,student=0;
		 float final_grade[50];
		float grades,grad[50],finalgrade=0;
		string course_name,corse_nam[50];
		node*next;
		node*prev;
		node(int value){
			next=NULL;
			prev=NULL;
			student=value;
		
			cout<<"ENTER THE NO OF COURSES of student: "<<student+1<<endl;
			cin>>no_of_courses;
			cout<<"ENTER THE NAMES AND THE GRADE OF COURSES: "<<endl;
			for(int i=0;i<no_of_courses;i++){
				cout<<"COURSE "<<i+1<<endl;
			cin>>course_name;
			corse_nam[i]=course_name;
			cout<<"GRADE OF its COURSE "<<i+1<<endl;
			cin>>grades;
			grad[i]=grades;
		}
		//for cgpa of all courses by a single student
			for(int i=0;i<no_of_courses;i++){
				finalgrade+=grad[i];
			}
			final_grade[student]=finalgrade/no_of_courses;
			cout<<"CGPA    "<<final_grade[student]<<endl;
		}
};

//class node2{
//	
//	public:
//		node2 *left;
//		node2 *right;
//		int data;
//		node2(int value){
//			data=value;
//			left=right=NULL;	
//		}	
//};
//class tree{
//	public:
//	node2 *root;
//	tree(){
//		root=NULL;
//	}
//	void insert(int value){
//		node *newnode= new node2(value);
//		if(root==NULL){
//			root=newnode;
//		}
//		else{
//			node2 *temp1=root;
//			node2 *temp2=root;
//			while(true){
//			temp2=temp1;
//			if(value<temp1->data){
//				temp1=temp1->left;
//				if(temp1==NULL){
//					temp2->left=newnode;
////					cout<<temp1->data<<" ";
//					break;
//				}
//			}
//				else {
//				if (value>temp1->data){
//				temp1=temp1->right;
//				if(temp1==NULL){
//					temp2->right=newnode;
////					cout<<temp1->data<<" ";
//					break;
//				}
//			}
//}
//		}
//		}
//		 
//	}
//};
class student_managment{
	public:
		node*head;
		student_managment(){
			head=NULL;
			
		}
		void list_of_student(int value)
		{
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
//			void display(float final_grad[],string arr[],int &count,int front){
//				int x;
//				cout<<"1 for DETAILED INFO of current students: \n2 for just name and roll no of current students\n";
//				cin>>x;
//				if(x==1){
//				node*temp=head;
//				while(temp!= NULL){
//					cout<<"ROLL NO "<<temp->student+1<<" "<<arr[temp->student+1]<<" has "<<temp->no_of_courses<<" courses with cgpa "<<temp->final_grade[temp->student+1]<<endl;
//					temp=temp->next;
//				}
//				cout<<endl;
//			}
//			if(x==2){
//				for(int i=0;i<5;i++){
//					cout<<arr[i]<<" roll no "<<i+1<<" WITH FINAL GRADE "<<final_grad[i]<<endl;
//				}
//			}
//			
//			
//		}
void display(string arr[], int &count, int front) {
    int x;
   node *ptr;
   
    cout << "1 for DETAILED INFO of current students: \n2 for just name and roll no of current students\n";
    cin >> x;
    
    if (x == 1) {
        node* temp = head;
        while (temp != NULL) {      	
            cout << "ROLL NO " << (temp->student) + 1 ;
           
			cout<< " " << arr[front] ;
			
			cout<< " has " << temp->no_of_courses ;
			
			cout<< " courses with cgpa " << ptr->final_grade[front] << endl;
            
			temp = temp->next;
			front++;
        }
        
    }
    if (x == 2) {
        for (int i = front; i < count; i++) {
            cout << arr[i] << " roll no " << i + 1 << " WITH FINAL GRADE " << ptr->final_grade[i+1] << endl;
        }
    }
}
};
 // stack behaviiour 
void push(int &count,string arr[]){
	char x;
	cout<<"ENTER THE NAMES OF THE STUDENT  "<<endl;
	cin>>x;
				count+=1;
				arr[count]=x;
			}
			void pop(int &count,string arr[]){
				arr[count]=" ";
				count-=1;
			}
			// que behaviour
			void deque(string arr[],int & count,int &front){
			arr[front]=" ";
			front++;
		} 
void pass_out(string arr[],int & count,int &front){
	int x;
	cout<<"HOW MANY StuDENTS PASS THIS SEMESTER: \n";
	cin>>x;
	for (int i = 0; i < x; ++i) {
   deque(arr,count,front);
}
}
void swap(int &a, int &b){
			int c; 
			c=a;
			a=b;
			b=c;
		}
		void swap2(string &a, string &b){
			string c; 
			c=a;
			a=b;
			b=c;
		}
void sort(float final_grade[], string arr[], int count) {
    for (int i = count - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (final_grade[j] > final_grade[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap(final_grade[j], final_grade[j + 1]);
            }
        }
    }
}


			
int main(){
	student_managment std;
	node *ptr=std.head;
		int count=0,x,z,front=0;
		string arr[40],y;
	cout<<"ENTER THE NO OF STUDENTS who are enrolled in this semester: \n";
	cin>>count;
	cout<<"ENTER THE NAMES OF THE STUDENT roll wise: "<<endl;
		for(int i=0;i<count;i++){
            cout<<"student "<<i+1<<" NAME : ";
			cin>>y;
				arr[i]=y;
				std.list_of_student(i);
			}		

//std.display(ptr->final_grade,arr,count,front);
	cout<<"YOU WANT TO ENROLL NEW STUDENT: press 1  "<<endl;
	cout<<"YOU WANT TO expel  STUDENT: press 2  "<<endl;
cin>>x;
//stack 
if(x==1){
//	push(count,arr);
	
	cout<<"student "<<count+1<<" NAME : ";
			cin>>y;
				arr[count]=y;
				std.list_of_student(count);
	
}	

if(x==2){
	pop(count,arr);
}
cout<<endl;
//que

pass_out(arr,count,front);




//sort(ptr->final_grade,arr,count);



std.display(arr,count,front);
}
