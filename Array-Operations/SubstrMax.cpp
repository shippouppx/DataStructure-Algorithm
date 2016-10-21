class ArrayOperation{
public:
	int SubstrMax(int a[],int n)
    {
	   	if(a==NULL || n<2)
	   	{
			return 0;
	   	}
		  int cur=a[0];
		  int sum=cur;
		  int i;
		  for(i=1;i<n;i++)
		  {
		  	cur = cur < 0 ? 0 : cur;
		  	cur = cur + a[i];
		  	sum= sum < cur ? cur : sum;
		  }
	  	return sum;
    }
}
