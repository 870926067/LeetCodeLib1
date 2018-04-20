/*Q
Input  两个复数   “1+1i" "1+-2i"
Output 一个复数   "3+-i"
*/
/*S
字符串解析出“+”和"i"，然后实部和实部相乘+（-虚部和虚部相乘）
实部和虚部相乘再求和，字符串拼一个i即可
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

string complexNumberMultiply(string a, string b)
{
	string ans = "";
	//1解析“+”
	string t;
	vector<int> s1;
	vector<int> s2;
	stringstream sa(a);
	while (getline(sa, t, '+'))
	{
		//cout << t<<" ";
		int pos = t.find("i");
		if (pos >= 0)
		{
			t.erase(pos, 1);
		}
		int temp = atoi(t.c_str());
		//		cout << temp << " ";
		s1.push_back(temp);
	}
	stringstream sb(b);
	while (getline(sb, t, '+'))
	{
		//cout << t<<" ";
		int pos = t.find("i");
		if (pos >= 0)
		{
			t.erase(pos, 1);
		}
		int temp = atoi(t.c_str());
		//	cout << temp << " ";
		s2.push_back(temp);
	}

	//
	int r=0;//实部
	int com=0;//虚部
	r = s1[0] * s2[0] - s1[1] * s2[1];
	com = s1[0] * s2[1] + s1[1] * s2[0];
	string rr = to_string(r);
	string comr = to_string(com);
	ans = rr + "+" + comr + "i";
//	cout << ans << endl;
	return ans;
}

int main()
{
	//
	string a = "1+-1i";
	string b = "1+-1i";
	string s = complexNumberMultiply(a, b);
	cout << s << endl;
	getchar();
	return 0;
}