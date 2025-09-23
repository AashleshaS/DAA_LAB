#include<stdio.h>
#include<math.h>

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void merge(int arr[],int l,int m,int r,int n,int *pass){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1],R[n2];

	for(i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=arr[m+1+j];
	}
	i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			k++;
			i++;
		}else{
			arr[k]=R[j];
			k++;
			j++;
		}
	}
	while(i<n1){
		arr[k]=L[i];
		k++;
		i++;
	}
	while(j<n2){
		arr[k]=R[j];
		k++;
		j++;
	}

	//(*pass)++;
	printf("Pass: ");
	for(int p=l;p<=r;p++){
		printf("%d ",arr[p]);
	}
	printf("\n");
}

void mergeSort(int arr[],int l,int r,int n,int *pass){
	if(l<r){
		int m=floor((l+r)/2);

		mergeSort(arr,l,m,n,pass);
		mergeSort(arr,m+1,r,n,pass);
		merge(arr,l,m,r,n,pass);
	}
}


int main(){
	int n;
	printf("no of elements: ");
	scanf("%d",&n);

	int arr[n];
	printf("elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("Given array:\n");
	printArray(arr,n);

	int pass=0;
	mergeSort(arr,0,n-1,n,&pass);

	printf("Sorted array:\n");
	printArray(arr,n);

	return 0;
}