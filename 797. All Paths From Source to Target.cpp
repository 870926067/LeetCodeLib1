/*输出图里面起点到终点的路径*/
/*思路
肯定是递归的
怎么递归
可以参考深度优先遍历
怎么返回值？返回一个vector， 然后和原来的做一个拼接，在放到二维里面去
*/
#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> Anser;
vector<int> onePath(vector<vector<int>>& graph, int count,vector<int> ans)
{
	//最开始是第一行
	vector<vector<int>>::iterator p = graph.begin() + count;
	vector<int> Temp = *p;
	if (Temp.size() == 0)//如果是有环图就会死循环
	{
		return ans;
	}
	vector<int>ans2;
	for (vector<int>::iterator pp = Temp.begin(); pp != Temp.end(); pp++)
	{
		ans2=ans;
		int num = *pp;	
		ans2.push_back(num);
		if (num == graph.size() - 1)
		{
			//到达了最后一个点
			Anser.push_back(ans2);
			//return ans2;
		}
		else
		{
			ans2 = onePath(graph, num, ans2);
		}		
	}
	return ans2;
	//什么ans都会被返回
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
	vector<int> ans(1,0);
	ans = onePath(graph, 0, ans);
	return Anser;
}
int main()
{
	//
	vector<vector<int>> graph;
	int line1[] = { 4,3,1 };
	int line2[] = { 3,2,4 };
	int line3[] = { 3 };
	int line4[] = { 4 };
	size_t size1 = sizeof(line1) / sizeof(int);
	size_t size2 = sizeof(line2) / sizeof(int);
	size_t size3 = sizeof(line3) / sizeof(int);
	size_t size4 = sizeof(line4) / sizeof(int);
	vector<int> line11(line1, line1 + size1);
	vector<int> line22(line2, line2 + size2);
	vector<int> line33(line3, line3 + size3);
	vector<int> line44(line4, line4 + size4);
	graph.push_back(line11);
	graph.push_back(line22);
	graph.push_back(line33);
	graph.push_back(line44);
	vector<int> line5;
	graph.push_back(line5);



	vector<vector<int>> ansss = allPathsSourceTarget(graph);
	vector<vector<int>>::iterator p = ansss.begin();
	for (p; p != ansss.end(); p++)
	{
		vector<int> temp = *p;
		for (vector<int>::iterator pp = temp.begin(); pp != temp.end(); pp++)
		{
			cout << *pp << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}