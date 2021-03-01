# include<cstdio>
# include<vector>
# include<algorithm>
using namespace std;

struct info{
    double price;
    double quantity;
    double unit_price;
    info(double _quantity):quantity(_quantity){};
};

bool cmp(info a, info b){
	return a.unit_price>b.unit_price;
}

int main()
{
    int N;
	double D, max_profit;
    vector<info> stock;
    scanf("%d %lf",&N,&D);
    for(int i=0; i<N;i++){
        double q_temp;
        scanf("%lf",&q_temp);
		info temp = info(q_temp);
        stock.push_back(temp);
    }
    for(int i=0; i<N;i++){
        double p_temp;
        scanf("%lf",&p_temp);
        stock[i].price = p_temp;
        stock[i].unit_price = p_temp/stock[i].quantity;
    }
	sort(stock.begin(),stock.end(),cmp);
	for(int i=0; i<N; i++){
		if(D>stock[i].quantity)
		{
			max_profit+=stock[i].price;
			D -= stock[i].quantity;
		}
		else
		{
			max_profit+=stock[i].unit_price*D;
			break;
		}
	}
	printf("%.2lf",max_profit);
}