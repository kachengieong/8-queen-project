#ifndef Board_H
#define Board_H

class Board
{
public:
	Board();
	void getPos();
	int altPos(int, int);
	int colPos();
	int rowPos();
	void setPos(int, int);
	void setRowPos(int);
	void setColPos(int);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void printGrid();
	bool vertChecker();
	bool horChecker();
	bool diagChecker();
	void primaryLoop();
	void retractionMethod();
	bool lineChecker();
	int queenCount = 0;
private:
	const static int num_rows = 8;
	const static int num_cols = 8;
	int grid[num_rows][num_cols];
	int pos_row = 0;
	int pos_col = 0;
	int count = 1;
};
#endif
