#include<iostream>
#include"Sudoku.h"
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool Sudoku::check(int i ,int tempI ){
	int row = i/9 , col = i%9 , x , t ,bloCol ,bloRow ;
	for ( t=0 ; t<9 ; t++ ){					//check row
		if (tempI == map[9*row +t])return false;}


	for ( t=0 ; t<9 ;t++){						//check col
		if( tempI == map[9*t + col ] ) return false;}
	

	bloRow = row -  (row % 3);					//check block
	bloCol = col -  (col % 3);	
	for( t=bloRow ; t < bloRow + 3 ; t++ ){
		for ( x=bloCol ; x < bloCol+3  ; x++ ){
			if( map[ 9*t + x ] == tempI) return false;}
	}
	return true;
}


bool Sudoku::checkRead(){
	int i ,count=0,count2, row, col,x,t,bloCol,bloRow;
	for( i=0 ; i <MapSize; i++ ){
		if( map[i] !=0 ){
		count++;
		}
	}
	
	
	if( count < 17 ){
		cout << "0"<<endl;
		return false;
	}
	else if(count ==81){
		for(i =0 ; i<MapSize ; i++){
			count2=0;
			row = i/9 ; col = i%9 ;
			for ( t=0 ; t<9 ; t++ ){					//check row
				if (map[i] == map[9*row +t]){
					count2++ ;
				}
			}
			if ( count2 >1){
				cout <<"0";
				return false;
			}
			for ( t=0 ; t<9 ;t++){						//check col
				if( map[i]== map[9*t + col ] ) 
					count2++  ;
			}
			if( count2 >2){
				cout <<"0";
				return false;
			}
			bloRow = row -  (row % 3);					//check block
			bloCol = col -  (col % 3);	
			for( t=bloRow ; t < bloRow + 3 ; t++ ){
				for ( x=bloCol ; x < bloCol+3  ; x++ ){
					if( map[ 9*t + x ] == map[i])
						 count2++    ;
				 }
			}
			if ( count2>3){
				cout<<"0";
				return false;
			}
					
		}
		cout <<"1"<<endl;
		for(i=0;i<MapSize; i++){
			cout<<map[i];
			if(i%9==8)cout<<endl;
			else cout<<" ";
		}
		return false;
	}
	else return true;
}


void Sudoku::solve(){
	int i;
	if( checkRead() ) {
	

		for (i=0 ; i <MapSize ; i++) {Ans[i]=0; Bns[i]=0;}				// init my Ans
//		for (i=0 ; i <MapSize ; i++) {Qus[i] = map[i];}		// Qus = map
		if ( backtrack(0) ){
			cout <<2 ;
			return;
		}
		else {
			for(i=0 ; i<=MapSize ; i++){
				if( i == MapSize){
					cout<<"1" <<endl;
					for ( int t=0; t<MapSize; t++){
						cout <<Ans[t];
						if( t%9==8)cout<<endl;
						else cout <<" ";
					}
					return;
				} 
				else{
					if( Ans[i] != 0)
						continue;
					else{
						cout <<"0";
						return;
					}

				}
				
			}
		}
	}
	else return;
}



int Count=0;
bool Sudoku::backtrack(int i ){
	if ( i==81 ){
		for(int t=0 ; t<MapSize ; t++  ){
			Ans[t] = map[t] ;
		}
		if ( Count == 0 ){
		Count++;
		return false;
		}
		else return true;
	}
	
	if ( map[i] ==0 ){
		for(int tempI=1 ; tempI<10 ;tempI++ ){
			
			if( check(i,tempI ) == true  ) { 
				map[i] = tempI;
				if ( backtrack(i+1) )
				
					return true;
			}
		}
		map[i]=0;
		return false;
	}
			
	else if ( map[i] != 0 ){
		if(backtrack(i+1)) 
			return true;
	}
}

/*
bool Sudoku::trackback(int i){
	int k;
	if ( i == (-1) ){  
	   for( k=0 ; k<MapSize ;k++ )	{
		   Bns[k] = map[k];
	   }
	   return true;
	}
	if( map[i] ==0 ){
		for(int tempI = 9 ; tempI > 0 ;tempI--){
			if( check( i,tempI)==true ){
				map[i] = tempI;
				if(trackback(i-1))
					return true;
			}
		}
		map[i]=0;
		return false;
	}
	if (map[i] != 0){
		if(trackback(i-1))
			return true;
	}
}
*/
