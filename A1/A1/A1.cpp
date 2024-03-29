#include <iostream>
#include <map>
#include <string>
#include<time.h>
#include<windows.h>
using namespace std;

map<int, __int64> globalMemoryDict;

__int64 jumpTo(int n) {
	if (n <= 2) {
		//边界条件
		return n;
	}
	if (globalMemoryDict[n] != 0) {
		//全局字典中存有历史数据时，返回历史数据以防止数据被多次计算
		return globalMemoryDict[n];
	}
	else {
		//返回数据
		//从n-1阶跳一层到n阶的跳法 + 从n-2阶跳两层到n阶的跳法
		return globalMemoryDict[n] = jumpTo(n - 1) + jumpTo(n - 2);
	}
}


int getInt() {
	//安全地获得一个整数
	int num;
	while (!(cin >> num)) {
		cin.clear();
		cout << "输入有错，请重新输入：";
		while (cin.get() != '\n');
	}
	return num;
}


int main()
{
	int n = 0;
	cout << "输入整数，表示台阶数。 输入负数退出" << endl;
	while (true) {
		int n = getInt();
		if (n < 0) {
			break;
		}
		else {
			DWORD startTime = GetTickCount();
			cout << "跳法：" << jumpTo(n);
			DWORD endTime = GetTickCount();
			cout << " 用时：" << endTime - startTime << "毫秒" << endl;
		}
	} 
}

