#include<iostream>
#include"Sudoku.h"
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int buff[81];
Sudoku::Sudoku(){				// Initialize map??
	for(int i=0; i<MapSize; i++  )
		map[i]=0;
}  

/*
void Sudoku::giveQuestion(){
	cout << "0" <<endl<< "6"<<endl<< "9"<<endl<< "8"<<endl<< "7"<<endl<< "0"<<endl<< "0"<<endl<< "0"<<endl<< "0"<<endl <<
		    "4" <<endl<<"3" <<endl<<"7"<<endl<< "0" <<endl<<"0"<< endl<<"2"<<endl<<"0" <<endl<<"0"<<endl<< "1"<<endl<<
		    "0" <<endl<<"1"<<endl<< "0"<<endl<< "9"<<endl<< "3"<<endl<< "0"<<endl<< "0"<<endl<<"0"<<endl<< "7"<<endl<<
		    "6" <<endl<<"0"<<endl<< "0"<<endl<< "7"<<endl<< "0"<<endl<< "5"<<endl<<"9"<<endl<< "0"<<endl<< "3"<<endl<<
		    "7" <<endl<<"8"<<endl<< "0"<<endl<< "1"<<endl<< "9"<<endl<< "6"<<endl<< "0"<<endl<< "0"<<endl<< "5"<<endl<<
			"1" <<endl<<"9"<<endl<< "0"<<endl<<"2"<<endl<< "4"<<endl<< "3"<<endl<< "6"<<endl<< "7"<<endl<< "0"<<endl<<
			"0" <<endl<<"0"<<endl<< "1"<<endl<< "0"<<endl<< "0"<<endl<< "8"<<endl<< "0"<<endl<< "0"<<endl<< "4"<<endl<<
			"3" <<endl<<"0"<<endl<< "0"<<endl<< "0"<<endl<< "1"<<endl<< "0"<<endl<< "0"<<endl<< "0"<<endl<< "6"<<endl<<
			"0" <<endl<<"4"<<endl<< "0"<<endl<<"3" <<endl<<"5" <<endl<<"7"<<endl<< "1"<<endl<< "8"<<endl<< "9"<<endl;
}

void Sudoku::transform(){
	int i;
	

	changeNum( 1 , 1);	
	for(i=0 ; i<MapSize ;i++){
	   cout << map[i] ;
	   if( i%9==8 ) cout <<endl;
	   else cout <<" ";
	   
	}
}
*/
void Sudoku::readIn(){
	int i;
	i=0;
	for(i=0 ; i<MapSize ;i++){
		cin >> map[i] ;}
	
}

void Sudoku::changeNum(int a ,int b){
	int x ,y ,i;
	for (i=0 ; i<MapSize ; i++  ){ 
		if( map[i] == a) map[i] = b;
		else if(map[i]==b) map[i] = a;}
}

void Sudoku:: changeRow(int a,int b){
//	int A = a-(a%3) , B= b- (b%3) ;
	int t;
	for ( t=0 ; t<27 ; t++ ){
		buff[t] = map[9*a*3+t];
		map[9*a*3+t] = map[9*b*3+t];
		map[9*b*3+t] = buff[t];
	}
}

void Sudoku::changeCol(int a,int b){
	int t ; //, A =a/3 , B = b/3;
	
	for( t=0; t<27 ; t++ ){
		buff[ t ] = map[ 9*(t/3)+(t%3)+ a*3 ];
		map[9*(t/3)+ (t%3)+ a*3 ] = map[9*(t/3) + (t%3) +b*3];
		map[9*(t/3)+(t%3)+ b*3] = buff[t];	
	}
	
}

void Sudoku::rotate(int n){
	int u , t,  i  ,j , N ,v;
	N =n%4;
	for(v=1 ; v<=N ;v++){
		for(u=0; u<MapSize ;u++)
			{buff[u] = map[u];}
		for(t=0; t<MapSize	;t++){
			i = t/9;  j = t%9;
			map[ 9*j+8-i ] = buff[ t ];
		}
	}
}

void Sudoku::flip(int a){
	int t , i , j , k ,u;
	if( a == 0 ){						//flip vertically
		for(u=0 ; u<=8 ; u++){
			for( t =0 ;t <= 3 ; t++){
				k = map[ 9*u+t ];
				map[ 9*u+t] = map[ 9*u+8-t ];
				map[ 9*u+8-t ] = k;
			}
		}
	}
	else{								//flip horizontally
		for(t=0 ;t<=35 ;t++ ){
			i=t/9; j=t%9;
			k = map[t];
			map[t]=map[ 9*(8-i)+j ];
			map[ 9*(8-i)+j ] =k;}
	}
}

void Sudoku::testFun(){ 	// for main to print
//	for( int i=0;i<MapSize ; i++ ){
//		cout << Bns[i] <<" ";
//		if( i%9==8) cout <<endl;	
//	}
	cout <<endl;
	for( int i=0;i<MapSize; i++ ){
		cout << Ans[i] <<" ";
		if( i%9==8) cout <<endl;
	}
	cout << endl;
	for( int i=0; i<MapSize ; i++ ){
		cout << map[i] <<" ";
		if( i%9==8) cout << endl;
	}
}  
