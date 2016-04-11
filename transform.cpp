#include<iostream>
#include"Sudoku.h"
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
void Sudoku::transform(){
	        int i;


			        changeNum( 1 , 1);
					        for(i=0 ; i<MapSize ;i++){
								           cout << map[i] ;
										              if( i%9==8 ) cout <<endl;
													             else cout <<" ";

																         }
}

