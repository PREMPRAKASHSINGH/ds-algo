#include <iostream>
using namespace std;

int partition(int a[], int l, int r){
  int pivot = a[r]; //element at right index
  int pi = l; //pivot index set as left index

  /*loop through left index to upto right index
  and if element is less than pivot element swap it with element at pivot index*/
  for(int i=l; i<r; i++){
    if(a[i]<=pivot){
      swap(a[i],a[pi]);
      pi++;
    }
  }
  swap(a[pi], a[r]);
  return pi;
}
void quickSort(int a[], int l, int r){
  if(l<r){
    int pi = partition(a,l,r); //get the pivot index

    quickSort(a, l, pi-1);
    quickSort(a, pi+1, r);
  }
}
int main() {
	int a[10] = {9,1,8,2,7,3,6,4,5,2};
	cout<<"Array before quickSort is : ";
	for(int i=0;i<10;i++){
    cout<<a[i]<<" ";
	}
	quickSort(a,0,9);
	cout<<"\nArray after quickSort is ";
	for(int i=0;i<10;i++){
    cout<<a[i]<<" ";
	}
	return 0;
}
