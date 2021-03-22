# include <cstdio>
# include <iostream>
# include <string>
# include <stack>
# include <queue>
# include <map>
using namespace std;

struct node{
	double num;//操作数
	char op;//操作符
	bool flag;//true表示操作数，false表示操作符
}

string str;
stack <node> s;//存放操作符
queue <node> q;//存放后缀表达式
map <char,int> op;

void Change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){
			temp.flag = true; //标记是数字
			temp.num = str[i++] - '0';
			while(i<str.length()&&str[i]>='0'&&str[i]<=9)//因为数值可能会>10，因此可能出现连续的字符
			{
				temp.num = temp.num*10 (+ str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag = false;
			temp.op = str[i];
			while(op[str[i]]<op[s.top().op]) //利用map存放不同操作符的优先级，将*/优先级定为2，+-定为1
			{
				q.push(s.top());
				s.pop();
			}	
			s.push(temp);
			i++;			
		}
		while(!s.empty())
		{
			q.push(s.top());
			s.pop();
		}
	}

}

double Cal()
{
	double temp1, temp2;
	node cur,temp;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur.flag == true) s.push(cur);//如果是数字直接入栈
		else{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			switch(cur.op)
			{
				case '+':
					temp.num = temp1+temp2;
					break;
				case '-':
					temp.num = temp1-temp2;
					break;
				case '*':
					temp.num = temp1*temp2;
					break;
				case '/':
					temp.num = temp1/temp2;
					break;
			
			}
			temp.flag = true;
			s.push(temp);
		}	
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while(getline(cin,str),str!="0"){
		for(string::iterator it = str.end; it!=str.begin();i--)
			if(*it==' ')str.erase(it);
		while(!s.empty())s.pop();
		Change();
		printf("%.2f\n",Cal());
	}
	return 0;
}