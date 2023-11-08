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

    T query(int ql, int qr, int l, int r, int p=1){
        if(ql<=l && qr>=r) return arr[p];
        if(ql>r || qr<l) return def;
        T a = this->query(ql, qr, l, (l+r)/2, 2*p),
          b = this->query(ql, qr, (l+r)/2+1, r, 2*p+1);
        return combine(a,b);
    }

    void update(int ql, int qr, int l, int r, int val, int p=1){
        if(ql<=l && qr>=r){
            arr[p] = val;
            return;
        }
        if(ql>r || qr<l) return;
        this->update(ql, qr, l, (l+r)/2, val, 2*p);
        this->update(ql, qr, (l+r)/2+1, r, val, 2*p+1);
        arr[p] = combine(arr[2*p], arr[2*p+1]);
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
        return this->query(a,b, 0, size-1);
    }

    void update(int idx, int val){
        update(idx, idx, 0, size-1, val);
    }
};

int main(){
    SegTree<int> a({-1, 2, 4, 9});
    a.update(0, 100);
    cout << a.query(0,2) << '\n';
    a.update(0, -100);
    cout << a.query(0,2) << '\n';
}