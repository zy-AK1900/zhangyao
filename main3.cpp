#include<iostream.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	srand(time(NULL));//避免题目重复
	int i, j, x, y, t[100], b;//x,y表示两个数随机数，i表示题目的数量，t,b是在两个数相减中保证结果为正定义的变量
	int a[7];
	cout << "请输入要打印的题目数：" << endl;
	cin >> a[0];
	while (a[0] <= 0)  //题目数必须为正数
	{
		cout << "请重新输入有效的题目数：" << endl;
		cin >> a[0];
	};
	cout << "请选择否有乘除法（是1；否0）：" << endl;
	cin >> a[1];
	while ((a[1] != 1) && (a[1] != 0)) //只能选择1或0
	{
		cout << "请重新输入有效的数值：" << endl;
		cin >> a[1];
	};
	cout << "请输入运算数的范围：" << endl;
	cin >> a[2];
	while (a[2] <= 0)  //运算数必须为正数
	{
		cout << "请重新输入有效的范围：" << endl;
		cin >> a[2];
	};
	cout << "请选择结果有无负数（是1；否0）：" << endl;
	cin >> a[3];
	while ((a[3] != 1) && (a[3] != 0))  //只能选择1或0
	{
		cout << "请重新输入有效的数值：" << endl;
		cin >> a[3];
	};
	cout << "请选择结果有无余数（是1；否0）：" << endl;
	cin >> a[4];
	while ((a[4] != 1) && (a[4] != 0))  //只能选择1或0
	{
		cout << "请重新输入有效的数值：" << endl;
		cin >> a[4];
	};
	cout << "请输入要打印的列数： " << endl;
	cin >> a[5];
	while (a[5] <= 0)
	{
		cout << "请重新输入有效列数:  " << endl;
		cin >> a[5];
	};
	cout << "请输入每行间隔数: " << endl;
	cin >> a[6];

	int result[100], resulty[100] = { 0 }, daan[100], yushu[100] = { 0 };
	for (i = 0; i<a[0]; i++)
	{
		if (a[1] == 1)//有乘除法的运算
		{
			t[i] = rand() % 4;
		}
		else//无乘除法的运算
		{
			t[i] = rand() % 2;
		}
		x = rand() % a[2] + 1;
		y = rand() % a[2] + 1;
		if (t[i] == 0)//加法
		{


			if ((i + 1) % a[5] == 0)//判断是否换行
			{
				cout << i + 1 << "·" << x << "+" << y << "=";
				result[i] = x + y;
				if (a[6] != 0)
				{
					for (j = 0; j<a[6]; j++)
					{
						cout << endl;
					}
				}
			}
			else
			{
				cout << i + 1 << "·" << x << "+" << y << "=" << '\t';

			}

		}
		if (t[i] == 1)//减法，考虑是否存在负数
		{
			if (a[3] == 0)//不存在结果负数
			{
				b = x;
				x = y;
				y = b;

			}
			if (a[3] == 1)//存在结果是负数
			{

			}


			if ((i + 1) % a[5] == 0)//判断是否换行
			{
				cout << i + 1 << "·" << x << "-" << y << "=";
				result[i] = x - y;


				if (a[6] != 0)//如果间隔数不是零
				{

					for (j = 0; j<a[6]; j++)
					{
						cout << endl;
					}
				}
			}
			else
			{
				cout << i + 1 << "·" << x << "-" << y << "=" << '\t';

			}
		}
		if (t[i] == 2)//乘法
		{


			if ((i + 1) % a[5] == 0)//判断是否换行
			{
				cout << i + 1 << "·" << x << "*" << y << "=";
				result[i] = x*y;
				if (a[6] != 0)
				{


					for (j = 0; j<a[6]; j++)
					{
						cout << endl;
					}
				}
			}
			else
			{
				cout << i + 1 << "·" << x << "*" << y << "=" << '\t';
			}

		}
		if (t[i] == 3)//除法，考虑结果是否有余数
		{
			if (a[4] == 1)//结果有余数
			{
			}
			else
			{
				while (x%y != 0)//不能整除，重新生成随机函数
				{
					x = rand() % a[2] + 1;
					y = rand() % a[2] + 1;
				};

			}


			if ((i + 1) % a[5] == 0)//判断是否换行
			{

				cout << i + 1 << "·" << x << "/" << y << "=";
				result[i] = x / y;
				resulty[i] = x%y;
				if (a[6] != 0)
				{
					for (j = 0; j<a[6]; j++)
					{
						cout << endl;
					}
				}
			}
			else
			{
				cout << i + 1 << "·" << x << "/" << y << "=" << '\t';
			}
		}
	}
	cout << "请输入解题答案" << endl;
	for (i = 0; i<a[0]; i++)
	{
		cout << i + 1 << ".";
		if (t[i] == 3)
		{
			cout << "请输入商：";
			cin >> daan[i];
			cout << "请输入余数：";
			cin >> yushu[i];
		}
		else
		{
			cin >> daan[i];
		}
		if (t[i] == 3)
		{
			if (daan[i] == result[i] && yushu[i] == resulty[i])
			{
				cout << "答案正确，请输入下一题答案" << endl;
			}
			else
			{
				cout << "答案错误,正确答案为：" << result[i] << "  " << resulty[i] << endl;
			}
		}
		else
		{
			if (daan[i] == result[i])
			{
				cout << "答案正确" << endl;
			}
			else
			{
				cout << "答案错误，正确答案为：" << result[i] << endl;
			}
		}
	}
	cout << "结束，欢迎使用" << endl;
}