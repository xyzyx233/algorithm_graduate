#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int A[5000000];

class sortt{
private:
    int n,k;
public:
    sortt(int n,int k){
        this->k=k-1;
        this->n=n;
    }
    void quciksort(){
        qqsort(A,0,n-1,k);
    }
    void qqsort(int A[],int low,int high,int k){
        int last;
        if(low==high){
            printf("%d", A[low]);
            return;
        }
        if(low<high)
        {
            last=low;

            for(int i=low+1;i<=high;i++)
            {
                if(A[i]>A[low])
                    swap(A,++last,i);
            }

            swap(A,last,low);
            if(k==last){
                printf("%d", A[last]);
                return;
            }
            if(k<last)
            qqsort(A, low, last - 1, k);
            if(k>last)
            qqsort(A, last + 1, high, k);
        }
    }
    void swap(int s[],int i,int j)
    {
        int temp;
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    void show(){
        printf("%d",A[k]);
    }
};
int main() {
//    int X[10]={1, 3, 5, 7, 4, 2, 6, 8, 34, 457};
    int kth=0,n=0;
    scanf("%d %d", &n,&kth);
    for(int i=0;i<n;i++){
//        A[i]=X[i];
        scanf("%d", &A[i]);
    }
    sortt s= sortt(n,kth);
    s.quciksort();
//    s.show();
    return 0;
}