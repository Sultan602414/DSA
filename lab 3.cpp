#include<iostream>
using namespace std;


void init(){
	char A[4][4][4][4]={};
	
for (int i = 0; i < 4; i++) {
 for (int j = 0; j < 4; j++) {
 for (int k = 0; k < 4; k++) {
 for (int l = 0; l < 4; l++) {	
 	
 A[i][j][k][l] = ('*');
}
}
}
}
	
}
void print_board(char A[][][][]){
	
		for (int i = 0; i < 4; i++) {
 for (int j = 0; j < 4; j++) {

 	
 cout<<"\t"<<A[j][j][j][j] ;
}
 if((i+1)%1==0){
 	cout<<endl<<endl;
}
}

}
int main(){
	char A[][][][];
	init();
	print_board(char A[][][][]);
	

	
	
	
	
}