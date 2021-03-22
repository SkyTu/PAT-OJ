# include<cstdio>
# include<algorithm>
# include<cmath>
const double pi = acos(-1.0); //PI
const double eps = 1e-5; //¾«¶Èµ½1e-5
using namespace std;

double area(double height, double R)
{
	double alpha = 2*acos((R-height)/R);
	return alpha*R*R/2;
}

double height(double R, double ratio)
{
	double S2 = pi*R*R/2, S1 = S2*ratio,left = 0,right = R,mid;
	while(right-left>eps){
		mid = (right+left)/2;
		if(area(mid,R)>S1)
			right = mid;
		else
			left = mid;
	}
	return mid;
}

int main()
{
	double h = height(5.2,0.5);
	printf("%lf",h);
}