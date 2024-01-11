#include <iostream>

template<typename T>
void bubble_sort(T*, int);

int main() {
    int arr[] = { 9,8,6,4,3,57,4,21,6,-1,0,2 };

    std::cout << "Before Sorting:\n";
    for ( int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++ ) std::cout << arr[i] << ' ';

    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    std::cout << "\nAfter Sorting:\n";
    for ( auto& c : arr ) std::cout << c << ' ';

    std::cout << '\n';
    return 0;
}

template<typename T>
void bubble_sort(T* arr, int n) {
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n - i - 1; j++ )
            if ( arr[j] > arr[j + 1] )
                std::swap(arr[j + 1], arr[j]);
}