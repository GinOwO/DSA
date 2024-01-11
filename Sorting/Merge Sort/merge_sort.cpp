#include<iostream>
#include<vector>

std::vector<int> merge_sort(const std::vector<int>&);
std::vector<int> merge(const std::vector<int>&, const std::vector<int>&);

int main() {
    std::vector<int> arr = { 9,8,7,6,5,3,4,2,-1,0,1 };

    std::cout << "Before Sorting:\n";
    for ( int& c : arr ) std::cout << c << ' ';

    std::vector<int> v = merge_sort(arr);

    std::cout << "\nAfter Sorting:\n";
    for ( int& c : v ) std::cout << c << ' ';
    std::cout << '\n';
}

std::vector<int> merge_sort(const std::vector<int>& arr) {
    int n = arr.size();
    if ( n == 1 ) return arr;

    std::vector<int> a(arr.begin(), arr.begin() + n / 2);
    std::vector<int> b(arr.begin() + n / 2, arr.end());
    return merge(merge_sort(a), merge_sort(b));
}

std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b) {
    int i = 0, j = 0;
    std::vector<int> sorted;
    while ( i < a.size() && j < b.size() ) {
        if ( a[i] < b[j] ) sorted.push_back(a[i++]);
        else sorted.push_back(b[j++]);
    }
    while ( i < a.size() ) sorted.push_back(a[i++]);
    while ( j < b.size() ) sorted.push_back(b[j++]);
    return sorted;
}