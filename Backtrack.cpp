#include <iostream>
#include <string>
#include <fstream>
using namespace std;	
int solve = 0;	//标记是否有解
void Backtrack(int *S,int *S1,int i,int sum,int n,int c)
{	//Backtrack（总集S，子集S1，当前解空间树层数i，子集总和sum，S大小n，目标值c）
	if (solve == 1)		//找到一组解后直接结束递归
		return;
	if (i == n) 
	{	if (sum == c)		//打印满足条件的一组解
		{	for (int i = 0; i < n; i++)
				if (S1[i] == 1)
					cout << S[i] << " ";
				else continue;
			solve = 1;		//标记有解
		}
		return;
	}
	if (sum + S[i] <= c)	//依次递归探索所有总和不大于目标值组合情况
	{	S1[i] = 1;
		sum += S[i];
		Backtrack(S, S1, i + 1, sum, n, c);
		sum -= S[i];		//若此次递归无解则回溯到上一状态继续
	}
	S1[i] = 0;			//若后续总和超过目标值则无需计算后续情况
	Backtrack(S, S1, i + 1, sum, n, c);
}

int main()
{	int n;	//n为S的大小
	int c;	//c为子集和的目标值
	string s;
	freopen("./input.txt", "r", stdin);		//输入重定向，从input.txt读取数据
	freopen("./output.txt", "w", stdout);	//输出重定向，向output.txt输出数据 
	cin >> n;
	cin >> c;
	int *S = new int[n];	//集合S
	int *S1 = new int[n];	//子集组合情况S1
	for (int i = 0; i < n; i++)
		cin >> S[i];
	for (int i = 0; i < n; i++)		//对子集S1进行初始化
		cin >> S1[i];
	Backtrack(S, S1, 0, 0, n, c);
	if (!solve)		//若无解则输出提示信息
		cout << "No Solution!" << endl;
	freopen("CON", "w", stdout);			//输出重定向，将输出流重定向到控制台
	ifstream input("./input.txt");			//将input.txt文件内容显示在控制台中
	cout << "文件input.txt" << endl;
	while (getline(input, s))				//逐行输出
		cout << s << endl;
	ifstream output("./output.txt");		//将output.txt文件内容显示在控制台中
	cout << "文件output.txt" << endl;
	while (getline(output, s))
		cout << s << endl;
	fclose(stdin);			//关闭重定向输入
	fclose(stdout);			//关闭重定向输出
	return 0;
}

