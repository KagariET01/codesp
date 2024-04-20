#include <bits/stdc++.h>
#define DBG if (debug)

#define endl '\n'

#define 整數 int
#define 長整數 long long int
#define 無負號 unsigned
#define 無負號長整數 unsigned long long int
#define 布林 bool
#define 小數 float
#define 超級小數 double
#define 字元 char
#define 字串 string
#define 換行 endl
#define 標準輸入 cin
#define 標準輸出 cout
#define 輸入 cin
#define 輸出 cout
#define 模板 template
#define 不會超時 \
	cin.tie(0);        \
	cout.tie(0);       \
	ios::sync_with_stdio(0);
#define 回傳 return
#define 主程式 int main
#define 如果 if
#define 否則如果 else if
#define 否則 else
#define 計數迴圈 for
#define 條件迴圈 while
#define 超級陣列 vector
#define 一對 pair
#define 排列 queue
#define 堆疊 stack
#define 管子 deque
#define 集合 set
#define 字典 map
#define 自動 auto
#define 型態名 typename
#define 除錯 DBG
#define 使用 using
#define 名稱空格 namespace
#define 假 false
#define 真 true
#define 設成 =
#define 是否為 ==
#define 是 ==
#define 加 +
#define 減 -
#define 乘 *
#define 除 /
#define 求餘 %
#define 算且 &
#define 算或 |
#define 算亦或 ^
#define 且 &&
#define 或 ||
#define 亦或 ^^
#define 非 !
#define 減一 --
#define 加一 ++
#define 大於 >
#define 小於 <
#define 大於等於 >=
#define 小於等於 <=
#define 讀入一行 getline
#define ； ;
#define ｢ {
#define ｣ }
#define ， ,
#define 設定寬度 setw
#define 桶子 stack
#define 推入 push
#define 丟掉 pop
#define 頂端 top

使用 名稱空格 std;

#define 讀取(型態) 讀取器<型態>()

模板<型態名 某型態> 某型態 讀取器()｢
	某型態 想回傳的東西 ；
	輸入 >> 想回傳的東西 ；
	回傳 想回傳的東西 ；
｣

主程式()｢
	不會超時 ；
	字串 目前這一行 ；
	桶子<字串>這個桶子 ；
	條件迴圈(輸入>>目前這一行)｢
		如果 (目前這一行 是 "[prev]")｢
			這個桶子.丟掉()；
		｣ 否則 ｢
			這個桶子.推入(目前這一行)；
		｣
	｣
	輸出<<這個桶子.頂端()<<換行 ；
	回傳 0 ；
｣
