class ArrayOperation{
public:
	int MaxSubTwoArraySum(int arr[],int length)
	{
		if(arr==NULL || length<2)
		{
			return 0;
		}
		int *h=new int[length];
		int cur=arr[length-1];
		int res=0;

		h[length-1]=arr[length-1];
		int i=length-2;
		for(i;i>=0;i--)
		{
			cur = cur<0 ? 0:cur;
			cur += arr[i];
			res = cur > res ? cur:res;
			h[i] = res;
		}

		int sum=arr[0]+h[1];
		int lres=arr[0];
		cur=arr[0];
		for(i=1;i<length-1;i++)
		{
			cur = cur<0? 0:cur;
			cur += arr[i];
			lres = cur > lres ? cur:lres;
			sum = lres+h[i+1]>sum? lres+h[i+1] : sum;
		}
		return sum;
	}
}