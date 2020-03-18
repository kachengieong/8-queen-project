#include "Board.h"
#include<iostream>
using namespace std;

Board::Board()
{
	for (int i = 0; i < num_rows; i++)
		for (int j = 0; j < num_cols; j++)
			grid[i][j] = 0;
	primaryLoop();
}
void Board::getPos()
{

}
int Board::altPos(int x, int y)
{
	return grid[x][y];
}
int Board::colPos()
{
	return pos_col;
}
int Board::rowPos()
{
	return pos_row;
}
void Board::setPos(int x, int y)
{
	grid[x][y] = 1;
}
void Board::setRowPos(int x)
{
	pos_row = x;
}
void Board::setColPos(int x)
{
	pos_col = x;
}
void Board::moveUp()
{
	if (rowPos() <= 0)
		return;
	else
	{
		setRowPos(rowPos() - 1); 
		return;
	}
}
void Board::moveDown()
{
	if (rowPos() >= num_rows - 1) 
		return; 
	else
	{
		setRowPos(rowPos() + 1);
		return;
	}
}
void Board::moveLeft()
{
	if(colPos() <= 0) {
		if (rowPos() > 0) 
		{ 
			setRowPos(rowPos() - 1); 
			setColPos(7); 
			return; 
		}
		else 
			return;
	}
	else {
		setColPos(colPos() - 1);
		return;
	}
}
void Board::moveRight()
{
	if (colPos() >= (num_cols - 1)) {
		if (rowPos() < num_rows - 1) 
		{ 
			setRowPos(rowPos() + 1); 
			setColPos(colPos() - 7); 
		}
		else 
			return; 
	}
	else
	{
		setColPos(colPos() + 1);
		return;
	}
}
void Board::printGrid()
{
	cout << count++ << endl;
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
			cout << grid[i][j];
		cout << endl;
	}
	cout << endl;
	cout << count++ << endl;
	for (int i = 0; i < num_cols; i++) {
		for (int j = 7; j >= 0; j--) 
			cout << grid[j][i];
		cout << endl;
	}
	cout << endl;

	cout << count++ << endl;
	for (int i = 7; i >= 0; i--) {
		for (int j = 7; j >= 0; j--)
			cout << grid[i][j];
		cout << endl;
	}
	cout << endl;

	cout << count++ << endl;
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < num_cols; j++) 
			cout << grid[j][i];
		cout << endl;
	}
	cout << endl;

}
bool Board::vertChecker()
{
	int y = colPos();
	for (int x = 0; x < num_rows; x++) {
		//y stays constant here and x will traverse down the row similar to the horizontal check that was posted
		if (grid[x][y] == 1) 
			return false; 
	}
	return true;
}
bool Board::horChecker()
{
	int r = rowPos();
	for (int j = 0; j < num_cols; j++)
	{
		if (grid[r][j] == 1)
			return false;
	}
	return true;
}
bool Board::diagChecker()
{
	int w = rowPos(), u = colPos();
	//up/right
	for (int v = 0; (w - v >= 0) && (u + v <= 7); v++) {
		if (grid[w - v][u + v] == 1) 
			return false;
	}
	//up/left
	for (int v = 0; (w - v >= 0) && (u - v >= 0); v++) {
		if (grid[w - v][u - v] == 1) 
			return false; 
	}
	//down/right
	for (int v = 0; (w + v <= 7) && (u + v <= 7); v++) {
		if (grid[w + v][u + v] == 1)
			return false; 
	}
	//down/left
	for (int v = 0; (w + v <= 7) && (u - v >= 0); v++) {
		if (grid[w + v][u - v] == 1) 
			return false; 
	}
	return true;
}
void Board::retractionMethod()
{
	for (int qSet = (queenCount - 1); queenCount > qSet;) {
		if (grid[rowPos()][colPos()] == 0) 
		{ 
			moveLeft(); 
		}
		if (grid[rowPos()][colPos()] == 1) 
		{
			grid[rowPos()][colPos()] = 0;
			queenCount--;
			moveRight();
		}
	}
}
bool Board::lineChecker()
{
	if(rowPos() != 7 && colPos() == 7 && grid[rowPos()][colPos()] == 0)
	{
		if (horChecker() == true) 
		{
			cout << "missing line" << endl;  
			return true;
		}
	}
	return false;
}
void Board::primaryLoop()
{
	int solutionCount = 0;
	while (solutionCount < 92) {
		if (grid[rowPos()][colPos()] == 0) {
			if (vertChecker() == true && horChecker() == true && diagChecker() == true) {
				grid[rowPos()][colPos()] = 1; 
				queenCount++; 
				moveRight();
			}
			else 
			{ 
				moveRight(); 
			}
		}
		if (rowPos() == 7 && colPos() == 7) {
			//printer method call
			if (queenCount == 8) 
			{
				printGrid(); 
				solutionCount += 4; 
			} //remove println in fnal ver.
			else 
			{ 
				retractionMethod(); 
			}
			retractionMethod();
		}
	}
		cout << "finished" << endl;
		cout << solutionCount << endl;
}
