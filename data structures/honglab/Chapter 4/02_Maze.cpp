#include <iostream>

#include "01_Stack.hpp"

using namespace std;

constexpr int kNumRows = 10;
constexpr int kNumCols = 9;

char maze[kNumRows][kNumCols] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '0', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1'},
	{'1', '1', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G'를 만나면 종료
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void PrintMaze()
{
	for (int j = 0; j < kNumRows; j++)
	{
		for (int i = 0; i < kNumCols; i++)
			cout << maze[j][i] << " ";
		cout << endl;
	}
}

struct Pos
{
	int row;
	int col;

	// 디버깅을 위한 편의 기능
	friend ostream& operator<<(ostream& os, const Pos& pos)
	{
		cout << "(" << pos.row << ", " << pos.col << ")" << flush;
		return os;
	}
};

int RecurMaze(Pos p)
{
	// 맵 밖으로 나가는 재귀호출 차단
	if (p.col > kNumCols || p.row > kNumRows)
		return 0;
	
	const char mark = maze[p.row][p.col];

	switch(mark)
	{
		// 찾은 경우
		case 'G':
			cout << "Found!" << endl;
			return 1;
		
		// 이미 방문한 위치인 경우
		case 'X':
			// FALLTHROUGH
		// 진행할 수 없는 위치인 경우
		case '1':
			return 0;
		
		// 시작 위치인 경우
		case 'S':
			// FALLTHROUGH
		// 진행할 수 있는 위치인 경우
		case '0':
			maze[p.row][p.col] = 'X';

			if (RecurMaze({ p.row, p.col + 1 }) == 1) return 1; // 오른쪽
			else if (RecurMaze({ p.row + 1, p.col }) == 1) return 1; // 아래
			else if (RecurMaze({ p.row - 1, p.col }) == 1) return 1; // 위
			else if (RecurMaze({ p.row, p.col - 1 }) == 1) return 1; // 왼쪽

			else maze[p.row][p.col] = '0';
	}
	return 0;
}

void StackMaze()
{
	Stack<Pos> s;

	s.Push({ 1, 1 });	// i = 1, j = 1  시작 지점
	

	while (!s.IsEmpty())
	{

		Pos p = s.Top();
		s.Pop();
		if (p.col > kNumCols || p.row > kNumRows)
			continue ;

		const char mark = maze[p.row][p.col];

		switch(mark)
		{
			// 찾은 경우
			case 'G':
				cout << "Found!" << endl;
				return ;	// 스택 소멸자 호출되겠지 아 ㅋㅋㅋ
			
			// 이미 방문한 위치인 경우
			case 'X':
				// FALLTHROUGH
			// 진행할 수 없는 위치인 경우
			case '1':
				break ;
			
			// 시작 위치인 경우
			case 'S':
				// FALLTHROUGH
			// 진행할 수 있는 위치인 경우
			case '0':
				maze[p.row][p.col] = 'X';
				s.Push({ p.row, p.col + 1 }); // 오른쪽
				s.Push({ p.row + 1, p.col }); // 아래
				s.Push({ p.row - 1, p.col }); // 위
				s.Push({ p.row, p.col - 1 }); // 왼쪽
				break ;
			default:
				break ;
		}
	}
}

int main()
{
	PrintMaze();

	RecurMaze({ 1, 1 });

	// StackMaze();

	PrintMaze();

	return 0;
}