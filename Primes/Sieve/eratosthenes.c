#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* sieve(int n){
    int* arr = (int*)malloc((n+1)*sizeof(int));
    arr[2]=1;
    for(int i=3; i<=n; i+=2) arr[i]=1;

    for(int i=3; i*i<=n; i++){
        if(arr[i]){
            for(int j=i*i; j<=n; j+=i)
                arr[j] = 0;
        }
    }
    return arr;
}

int main(){
    int n; scanf("%d", &n);
    int* arr = sieve(n);
    for(int i=0; i<=n; i++)
        if(arr[i]) printf("%d ", i);
    puts("");
    free(arr);
}