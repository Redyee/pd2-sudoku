#include<iostream>
#include<vector>
using namespace std;
class Sudoku{
	public:
		Sudoku();
		void giveQuestion();
		void transform();
		void readIn();
		void changeNum(int a , int b);
		void changeRow(int a , int b);
		void changeCol(int a , int b);
		void rotate(int a);
		void flip(int n);

		void testFun();
		static const int MapSize = 81;
		void solve();
		bool backtrack(int i);
		bool trackback(int i);
		bool check(int i ,int tempI);
		bool checkRead();
	private:
		
		int map[MapSize];
		int Qus[MapSize];
		int Ans[MapSize];
		int Bns[MapSize];
		int count;
};
