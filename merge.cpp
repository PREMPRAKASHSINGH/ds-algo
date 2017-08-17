#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r){
  int i,j,k;
  int n1 = m-l+1;
  int n2 = r-m;
  //create L[n1], R[n2] temp arrays
  int L[n1], R[n2];
  for(i=0;i<n1;i++){
    L[i] = a[l+i];
  }
  for(j=0;j<n2;j++){
    R[j] = a[m+1+j];
  }
  //merge L[n1], R[n2] into a[l...r]
  i=0,j=0,k=l;
  while(i<n1 && j<n2){
    if(L[i]<R[j]){
      a[k] = L[i];
      i++;
    }else{
      a[k] = R[j];
      j++;
    }
    k++;
  }
  //if any one of the array(L[n1] & R[n2]) gets exhausted copy that into a[l...r]
  while(i<n1){
    a[k] = L[i];
    i++;
    k++;
  }
  while(j<n2){
    a[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(int a[], int l, int r){
  if(l<r){
    //find middle
    int m = (l+r)/2;
    //sort the 2 halves
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    //merge the 2 halves
    merge(a, l, m, r);
  }
}

int main() {
  int i;
  int a[10] = {1,9,2,8,3,7,4,6,5,2};
  cout<<"Array before merge sort is ";
  for(i=0;i<10;i++){
    cout<<a[i]<<" ";
  }
  mergeSort(a, 0 , 9);
  cout<<"\nArray after merge sort is ";
  for(i=0;i<10;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
