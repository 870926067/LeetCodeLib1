/*Question
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so 
that they match the order that S was sorted. More specifically, if x occurs before y in S, 
then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input:
S = "cba"
T = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.*/

/*解析思路
其实就是有一套新的排序规则，然后用这个规则排序，排序算法可以是归并啊快排啊冒泡。
粗暴解法：遍历一遍又一遍，S里读到一个a，就去找字符串里全部的A
精细解法：先用哈希表把S里的顺序存起来，对T排序时，一个字符能快速找到它的排序位置。哈希可以用char的asc码排。
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


string customSortString(string S, string T) 
{
	//先把S做成表
	int a[26];
	for (int m = 0; m < 26; m++)
	{
		a[m] = 26;
	}
	int lenofS = S.length();
	for (int i = 0; i < lenofS; i++)
	{
		int asc = S[i] - 'a';
		a[asc] = i;
	}
	//排序，这里其实可以用计数排序
	int b[26] = { 0 };//这里是已经排好序的，a里面等于0 的值，在b里就是第0位
	char c[26] = { 'a' };//c[0]表示排序为0 的字符是哪一个字符
	//b[a['a']]是排序第几的个数
	int lenofT = T.length();
	string asn = "";
	for (int i = 0; i < lenofT; i++)
	{
		int asc = T[i] - 'a';
		//会出现S里面没有的，这个时候把他直接输出就可以了。它会在字符串的最前面
		if (a[asc] == 26)
		{
			asn = asn + T[i];
		}
		else
		{
			b[a[asc]]++;
			c[a[asc]] = T[i];
		//	cout << a[asc] << endl;
		}
		
	}

	for (int j = 0; j < 26; j++)
	{
		for (int k = 0; k < b[j]; k++)
		{
			asn = asn + c[j];
		}
	}
	return asn;
}

int main()
{
	//
	string S = "cba";
	string T = "abcd";
	string ans = customSortString(S, T);
	cout << ans << endl;
	getchar();
	return 0;
}