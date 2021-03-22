# include <cstdio>
# include <iostream>
# include <string>
# include <stack>
# include <queue>
# include <map>
using namespace std;

struct node{
	double num;//������
	char op;//������
	bool flag;//true��ʾ��������false��ʾ������
}

string str;
stack <node> s;//��Ų�����
queue <node> q;//��ź�׺���ʽ
map <char,int> op;

void Change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){
			temp.flag = true; //���������
			temp.num = str[i++] - '0';
			while(i<str.length()&&str[i]>='0'&&str[i]<=9)//��Ϊ��ֵ���ܻ�>10����˿��ܳ����������ַ�
			{
				temp.num = temp.num*10 (+ str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag = false;
			temp.op = str[i];
			while(op[str[i]]<op[s.top().op]) //����map��Ų�ͬ�����������ȼ�����*/���ȼ���Ϊ2��+-��Ϊ1
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
		if(cur.flag == true) s.push(cur);//���������ֱ����ջ
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