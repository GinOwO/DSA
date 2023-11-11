#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TOLERANCE 1e-13

double exp(double m, int n){ // m**n
    double ans=1;
    while(n>0){
        if(n%2){
            ans *= m;
            n--;
        }
        else{
            m *= m;
            n/=2;
        }
    }
    return ans;
}

double nrt(unsigned long long n, int root){
    double l=0, r=n/2+1, mid, k;
    do{
        mid = (l+r)/2;
        k = exp(mid,root)-n;
        if(k>0) r=mid-TOLERANCE;
        else l=mid+TOLERANCE;
    } while(fabs(k)>TOLERANCE);

    return mid;
}

int main(){
    printf("%.12lf\n", nrt(2,3));
}