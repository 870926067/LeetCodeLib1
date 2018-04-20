/*
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/
/*===思路---最长子串问题
从头开始将字符串分成两半，两个字符串求最长子串
然后求出一个0最长子串，就重新开始循环
最坏的情况是，整条都没有重复的字符，这样要从头分到尾，n-1个分割，中分的时间复杂度是（n/2)^2所以复杂度是n^3????
*/
/*参考思路---贪心算法
对一个新出现的字符，找到它最晚出现的位置，只可能比这个后面，不可能比这个前面。这样分割匹配最长子串会少一点。
比如你用find找到第二个逗号的位置是7，那么找第三个逗号就可以用str.find(",", 7 + 1)
Let's try to repeatedly choose the smallest left-justified partition.
Consider the first label, say it's 'a'. The first partition must include it,
and also the last occurrence of 'a'. However, between those two occurrences of 'a', 
there could be other labels that make the minimum size of this partition bigger.
For example, in "abccaddbeffe", the minimum first partition is "abccaddb".
This gives us the idea for the algorithm: For each letter encountered, 
process the last occurrence of that letter, extending the current partition [anchor, j] appropriately.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
void Initial2Aray(int ** A, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			A[i][j] = 0;
		}
	}

}

int LCS(string & s1, string & s2)
{
	//如果要输出路径，必须从后往前回溯，否则把所有的+1的存起来
	//（注释的substring)会存所有相同的字符而不管顺序
	//初始化一张表
	//vector<char> substring;
	size_t s1Len = s1.length();
	size_t s2Len = s2.length();
	vector<vector<int>> p1(s1Len + 1, vector<int>(s2Len + 1,0));
/*	int **p1 = new int *[s1Len + 1];
	for (int i = 0; i <= s1Len; i++)
	{
		p1[i] = new int[s2Len + 1];
	}
	Initial2Aray(p1, s1Len + 1, s2Len + 2);*/
	//
	for (int i = 1; i <= s1Len; i++)
	{
		char c1 = s1[i - 1];
		for (int j = 1; j <= s2Len; j++)
		{
			char c2 = s2[j - 1];
			if (c1 == c2)
			{
				//斜对角加1
				//substring.push_back(c1);
				p1[i][j] = p1[i - 1][j - 1] + 1;
			}
			else
			{
				p1[i][j] = max(p1[i - 1][j], p1[i][j - 1]);
			}
		}
	}

	/*	for (vector<char>::iterator p3 = substring.begin(); p3 != substring.end(); p3++)
	{
	cout << *p3 << " ";
	}
	cout << endl;*/
	return p1[s1Len][s2Len];
}

vector<int> partitionLabels(string S) 
{//返回值是每个子串多长
	vector<int> ans;
	int lenS = (int)S.length();
	for (int i = 1; i <= lenS - 1; i++)
	{
		string s0 = S.substr(i - 1, 1);
		int pos = 0;
		while (pos >= 0)
		{
			i = pos+1;
			pos = (int)S.find(s0, pos + 1);
		}//加入贪心策略。但是这样在最后可能执行到最后一个字符都没有重的，s1会取全部的长，s2取空，这样i会被提前存进去的
		//所以在最后判断有length才加入，就不会超时了
		
		
/*		if (S[i - 1] == S[i])
		{
			continue;
		}//有一个测试用例aaaaaabbbbbbb这种，但如果abcdefg这种还是会超时*/
		string s1 = S.substr(0, i);
		cout << s1 << endl;
		string s2 = S.substr(i, lenS - i);
		cout << s2 << endl;
		int c = LCS(s1, s2);
		if (c == 0)
		{
			ans.push_back(i);
			S.erase(0, i);
			i = 0;
			lenS = S.length();
		}
	}
	//最后剩下一节没有存的
	if (S.length() != 0)
	{
		ans.push_back(S.length());
	}
	return ans;
}
int main()
{
	//
	string S = "vhaagbqkaq";
	//
	vector<int>ans;
	ans = partitionLabels(S);
	for (vector<int>::iterator p = ans.begin(); p != ans.end(); p++)
	{
		cout << *p << " ";
	}
	getchar();
	return 0;
}