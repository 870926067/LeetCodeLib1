/*问题
输出0到N之间，每个数字的二进制里面有多少个1
eg
For num = 5 you should return [0,1,1,2,1,2].
*/
/*思路，各位的变化规律是0 1 0 1。。。
到2的幂的时候，最高位是1，后面全是0
然后一个num，减去它前面的一个2的幂，就是后来加入的，只要用2的幂的1加上这个差就可以
所以这是一个有子问题的题，只要存储子问题的结果就会变得简单*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> countBits(int num) {
	vector<int> ans(1,0);
	if (num == 0)
	{
		return ans;
	}
/*	if (num == 1)
	{
		ans.push_back(1);
		return ans;
	}*/
	int i = 1;
	while (i <= num)
	{
		//找到它前一个2的幂
		//其实可以用一个数字存储那个2的幂，就不需要做下面这个循环了
		for (int j = 0;; j++)
		{
			if (pow(2, j) == i)
			{
				//i刚好是j的次幂,那么它里面是1个
				ans.push_back(1);
				break;
			}
			else if (pow(2, j) > i)
			{
				//i小于2的这个幂，那它前面的数字就是2的j-1次幂
				int cha = i - pow(2, j - 1);
				int an = ans[cha] + 1;
				ans.push_back(an);
				break;
			}
		}
		i++;
	}
//	cout << ans.size();
	return ans;

}

int main()
{
	int num = 5;
	vector<int> ans = countBits(num);
	//
	for (vector<int>::iterator p = ans.begin(); p != ans.end(); p++)
	{
		cout << *p << "  ";
	}
	getchar();
	return 0;
}
