# include<cstdio>

//假设A[]单调递增
int binarySearch(int A[], int left, int right, int x){
	int mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(A[mid]==x)
			return mid;
		else if(A[mid]>x)
			right = mid-1;
		else
			left = mid+1;
	}
	return -1;
}

int binarySearch_first_bigger_than_x	(int A[], int left, int right, int x){
	int mid;
	while(left < right)
	{
		mid = (left+right)/2;
		if(A[mid]>x)
			right = mid;
		else 
			left = mid+1;
	}
	return left;
}

int main(){
	const int n =10;
	int A[n] = {1,3,4,6,7,8,10,11,12,15};
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));
	return 0;
}