# include<iostream>
# include<cstdio>
# include<stack>
# include<vector>
# include<cmath>
using namespace std;

int main(){
	double num,sum=0;
	char opt,temp='1';
	vector<double> result;
	stack<double> num_stack;
	stack<char> opt_stack; 
	while(1){
		sum = 0;
		scanf("%lf",&num);
		getchar();
		if(num==0&&cin.peek()==EOF)
		    break;
		num_stack.push(num);
		temp = cin.peek();
		while(temp=='+'||temp=='-'||temp=='*'||temp=='/')
		{
			scanf("%s %lf",&opt,&num);
			switch(opt){ //加减后算，乘除先算
				case '+':
					num_stack.push(num);
					opt_stack.push(opt);
					break;
				case '-':
					num_stack.push(num);
					opt_stack.push(opt);
					break;
				case '/':
					num = num_stack.top()/num;
					num_stack.pop();
					num_stack.push(num);
					break;
				case '*':
					num = num_stack.top()*num;
					num_stack.pop();
					num_stack.push(num);
					break;
			}
			getchar();
			temp = cin.peek();
		}
		while(num_stack.size()!=1){
			opt = opt_stack.top();
			num = num_stack.top();
			opt_stack.pop();
			num_stack.pop();
			if(opt == '+')
				sum+=num;
			else
				sum-=num;
		}
		if(num_stack.top())
			sum += num_stack.top();
		num_stack.pop();
		result.push_back(sum);
		//printf("%.2f\n",sum);
	}
	int i = 0;
	for(vector<double>::iterator it = result.begin();it!=result.end();it++)
	{
		scanf("%lf",&num);
		i++;
		if(abs(num-*it)>=0.005)
			printf("第%d组，实际值%lf，计算值%.2lf",i,num,*it);
	}
	printf("finish");
	return 0;
}