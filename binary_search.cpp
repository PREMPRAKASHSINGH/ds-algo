#include <iostream>
using namespace std;

int binarySearch(int* a, int l, int r, int key){
  if(l<=r){
    int mid = (l+r)/2;
    if(a[mid] == key){
      return mid;
    }
    if(a[key]<mid){
      binarySearch(a, l, mid, key);
    }else if(a[key]>mid){
      binarySearch(a, mid+1, r, key);
    }
  }else{
    return -1;
  }
}

int main() {

  int list[] = {0,1,2,3,4,5,6,7,8,9};
  int key, index;
	cout<<"enter key to search in the list ";
	cin>>key;
	index = binarySearch(list, 0, 9, key);
	if(key == -1){
    cout<<key<<" not found in the list.";
	}else{
    cout<<key<<" found at index "<<index;
	}
	return 0;
}
