#include<iostream>
#include<vector>
using namespace std;
long long  merge(vector<int>&nums,vector<int>&temp,int low,int mid,int high){
    
    if(low>=high)
        return 0;
    
    
    long long res=0;
    long long j=mid;
    long long k=low;
    long long i=low;
    while(j<=high && i<mid){
        
        if(nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        }
        else{
            temp[k++]=nums[j++];
            res+=(mid-i);
        }
    }
    
    while(i<mid){
        temp[k++]=nums[i++];
    }
    
    while(j<=high){
        temp[k++]=nums[j++];
    }
    
    
    for (int m = low; m <= high; m++)
  nums[m] = temp[m];
    
    
    return res;
}

long long mergeSort(vector<int>&nums,vector<int>&temp,int low,int high){
    
    if(low>=high)
        return 0;
    
    long long mid=low+(high-low)/2;
    
    long long left=mergeSort(nums,temp,low,mid);
    long long  right=mergeSort(nums,temp,mid+1,high);
    
    return left+right+merge(nums,temp,low,mid+1,high);
    
}

int countInversion(vector<int>&nums){
    
    vector<int>temp(nums.size());
    return mergeSort(nums,temp,0,nums.size()-1);
    
}
int main(){
  int n; 
  cin>>n;
  vector<int>arr;
 arr.clear();
  for(int i = 0; i< n;i++)
  {
    int a ;
    cin>>a;
    arr.push_back(a);

  }

 // int arr[] = { 1, 20, 6, 4, 5 };
 //  n = sizeof(arr) / sizeof(arr[0]);
   long long ans = countInversion(arr);
 
  cout<<ans<<endl;

  return 0;
}