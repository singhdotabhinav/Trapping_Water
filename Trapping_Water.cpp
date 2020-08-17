int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
int trap(int* height, int heightSize){
    
    int n=heightSize;
    if(n==0)
        return 0;
    int mxl[n];
    int mxr[n];
    mxl[0]=height[0];
    for(int i=1;i<n;i++){
        mxl[i]=max(mxl[i-1],height[i]);
    }
    mxr[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        mxr[i]=max(mxr[i+1],height[i]);
    }
    int water[n];
    for(int i=0;i<n;i++){
        water[i]=min(mxl[i],mxr[i])-height[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=water[i];
    return sum;

}
