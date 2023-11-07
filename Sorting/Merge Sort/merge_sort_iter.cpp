#include<iostream>
#include<vector>
#include<queue>

std::vector<int> merge_sort(const std::vector<int>&);

int main(){
    std::vector<int> arr={9,8,7,6,5,3,4,2,-1,0,1};

    std::cout << "Before Sorting:\n";
    for(int&c: arr) std::cout << c << ' ';

    std::vector<int> v = merge_sort(arr);

    std::cout << "\nAfter Sorting:\n";
    for(int&c: v) std::cout << c << ' ';
    std::cout << '\n';
}

std::vector<int> merge_sort(const std::vector<int>&_arr){
    std::queue<std::vector<int>> que;
    std::vector<int> a, b;

    for(auto&c:_arr) que.push(std::vector<int>{c});

    while(que.size()>1){
        a = que.front(); que.pop();
        b = que.front(); que.pop();

        int i = 0, j = 0;
        std::vector<int> sorted;
        while (i<a.size() && j<b.size())
            sorted.push_back((a[i]<b[j])?a[i++]:b[j++]);

        while(i<a.size()) sorted.push_back(a[i++]);
        while(j<b.size()) sorted.push_back(b[j++]);
        que.push(sorted);
    }
    return que.front();
}
