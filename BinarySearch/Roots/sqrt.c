#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TOLERANCE 1e-13

double bsqrt(unsigned long long n){
    double l=0, r=n/2+1, mid, k;
    do{
        mid = (l+r)/2;
        k = mid*mid-n;
        if(k>0) r=mid-TOLERANCE;
        else l=mid+TOLERANCE;
    } while(fabs(k)>TOLERANCE);
    return mid;
}

int main(){
    printf("%.12lf\n", bsqrt(2));
}