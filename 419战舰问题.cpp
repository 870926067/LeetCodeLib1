/*问题解析
Input：X是战舰，·不是。战舰只可能是一行或者一列，不允许交叉
X..X
...X
...X
Output：几组战舰
2
额外要求，一次完成，不需要花费额外的空间
*/
/*
要求一次完成，即每个点只访问一次，想到图的遍历。
图的递归遍历要花费递归空间，而遍历要维护队列。
所以想找规律：
发现一组战舰里找到它的第一个元素即可。第一个元素左和上都没有，右和下有，所以形成判断条件。
非第一个元素左或者上有元素。有特殊情况，孤单的一个点，他上下左右都没有。
综合说，就是该元素要是X，然后左和上必须空即可。
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;




int countBattleships(vector<vector<char>>& board) 
{
	int ans = 0;
	int rows = board.size();
	vector<vector<char>>::iterator p = board.begin();
	vector<char> temp = *p;
	int cols = temp.size();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((board[i][j]=='X')&&(i - 1 < 0 || board[i - 1][j] != 'X') && (j - 1 < 0 || board[i][j - 1] != 'X'))
			{
				ans++;
			}
			//四个都空
		/*	if ((i - 1 < 0 || board[i - 1][j] != 'X') && (j - 1 < 0 || board[i][j - 1] != 'X') && (i + 1 >= rows || board[i + 1][j] != 'X') && (j + 1 >= cols || board[i][j + 1] != 'X'))
			{
				ans++;
			}
			//左上空且右下有一个不空
			else if ((i - 1 < 0 || board[i - 1][j] != 'X') && (j - 1 < 0 || board[i][j - 1] != 'X') &&
				(i + 1 < rows || j + 1 < cols) && 
				((i + 1 >= rows || board[i + 1][j] == 'X') || (j + 1 >= cols || board[i][j + 1] == 'X')))
			{
				ans++;
			}*/
		}
	}
	return ans;
}
int main()
{
	//Input
	char word1[] = { '.','.' };
	char word2[] = { 'X','X' };
	char word3[] = { '.','.','.','X' };
	size_t sizeofword = sizeof(word1) / sizeof(char);
	vector<char> line1(word1, word1 + sizeofword);
	vector<char> line2(word2, word2 + sizeofword);
	//vector<char> line3(word3, word3 + sizeofword);
	vector<vector<char>> board;
	board.push_back(line1);
	board.push_back(line2);
	//board.push_back(line3);
	//
	int ans = countBattleships(board);
	cout << ans << endl;
	//
	getchar();
	return 0;
}