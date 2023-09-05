#include<iostream>
#include<vector>

using namespace std;

int pivot_index(vector<int> arr, int n){
    int s=0,e=n-1;
    int mid= s+ (e-s)/2;
    int index;

    while(s<e){

        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }

        mid= (s+e)/2;
    }
    
    return s;
}

int binary_search(vector<int> arr,int start, int end, int n, int k){
    int s= start;
    int e= end;
    int mid=(s+e)/2;
    while(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            e=mid-1;;
        }
        else{
            s=mid+1;
        }

        mid =(s+e)/2;
    }

    return -1;
}

int main(){
    vector<int> arr;
    int size,temp;

    printf("Enter size: ");
    scanf("%d",&size);
    printf("Enter element in the array :- \n ");
    for(int i=0;i<size;i++){
        scanf("%d",&temp);
        arr.push_back(temp);
    }

    int k;
    printf("Enter element to be searched: ");
    scanf("%d",&k);
    int index= pivot_index(arr,size);
    int result;

    if(k>=arr[index] && k<=arr[size-1]){
        result = binary_search(arr,index,size-1,size,k);
    }
    else{
        result = binary_search(arr,0,index-1,size,k);
    }
    cout<<k<<" is at "<<result<<" index."<<endl;
    return 0;
}
