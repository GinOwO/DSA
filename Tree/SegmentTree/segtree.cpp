#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#include<climits>

using namespace std;

template<typename T>
class SegTree{
private:
    vector<T> arr; T def;
    const function<T(T, T)> combine;
    int size;

    void build(const vector<T>& inp, int l, int r, int p){
        if(l==r){
            arr[p]=inp[l];
            return;
        }
        int m = (l+r)/2;
        this->build(inp, l, m, 2*p);
        this->build(inp, m+1, r, 2*p+1);
        arr[p] = combine(arr[2*p], arr[2*p+1]);
    }

    int index(const pair<int, int>& q, const pair<int, int>& k, const int p=1){
        if(q.first<=k.first && q.second>=k.second) return p;
        if(q.first>k.second || q.second<k.first) return def;
        T a = this->index(q,{k.first, (k.first+k.second)/2}, 2*p),
          b = this->index(q,{(k.first+k.second)/2+1, k.second}, 2*p+1);
        return (a!=def)?a:b;
    }

    int index(int idx){
        return this->index({idx,idx},{0,size-1});
    }

    T query(const pair<int, int>& q, const pair<int, int>& k, const int p=1){
        if(q.first<=k.first && q.second>=k.second) return arr[p];
        if(q.first>k.second || q.second<k.first) return def;
        T a = this->query(q,{k.first, (k.first+k.second)/2}, 2*p),
          b = this->query(q,{(k.first+k.second)/2+1, k.second}, 2*p+1);
        return combine(a,b);
    }

    void update(int p){
        if(p<1) return;
        arr[p] = combine(arr[2*p], arr[2*p+1]);
        update(p/2);
    }

public:
    SegTree(const vector<T>& inp, int def = INT_MIN, 
    function<T(T, T)> cmp = [](T x,T y){return (x>y)?x:y;}) 
    : combine(cmp), def(def) {
        size = inp.size();
        arr = vector<T>(size*4+1, def);
        this->build(inp, 0, inp.size()-1, 1);
    }

    void print(){
        for(auto&c:arr) if(c!=def) cout << c << " ";
        cout << '\n';
    }

    T query(int a, int b){
        return this->query({a,b}, {0, size-1});
    }

    void update(int idx, int val){
        int ind = this->index(idx);
        if(ind==def) return;
        arr[ind] = val;
        update(ind/2);
    }
};

int main(){
    SegTree<int> a({-1, 2, 4, 9});
    a.update(0, 100);
    cout << a.query(0,2) << '\n';
    a.update(0, -100);
    cout << a.query(0,2) << '\n';
}