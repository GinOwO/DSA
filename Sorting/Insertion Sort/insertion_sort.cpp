#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>&);

int main(){
    std::vector<int> arr{9,8,6,4,3,57,4,21,6,-1,0,2};
    
    std::cout << "Before Sorting:\n";
    for(auto&c:arr) std::cout << c << ' ';
    
    insertion_sort(arr);
    std::cout << "\nAfter Sorting:\n";
    for(auto&c:arr) std::cout << c << ' ';

    std::cout << '\n';
    return 0;
}

void insertion_sort(std::vector<int>&arr){
    int n = arr.size();
    if (n<=1) return;
    int key, j;
    for(int i=1; i<n; ++i){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
            arr[j+1] = arr[j--];
        arr[j+1]=key;
    }
}