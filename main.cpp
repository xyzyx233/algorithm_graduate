#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
    double x,y;
};

Point list[1000000];

int CompX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int CompY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

double dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closestdis(Point* P,int n){
    if(n<=3){
        double min = INFINITY;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                if (dist(P[i], P[j]) < min)
                    min = dist(P[i], P[j]);
        return min;
    }
    int mid=n/2;
    Point midPoint = P[mid];
    double left=closestdis(P,mid);
    double right=closestdis(P+mid,n-mid);
    double min=(left<right)?left:right;
    int j = 0;
    Point list1[n];
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < min)
            list1[j] = P[i], j++;
    int len=j;
    qsort(list1,len, sizeof(Point),CompY);
    for (int i = 0; i < len; ++i)
        for (int j = i+1; j < len && (list1[j].y - list1[i].y) < min; ++j)
            if (dist(list1[i],list1[j]) < min)
                min = dist(list1[i], list1[j]);
    return min;
}

int main(){
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&list[i].x,&list[i].y);
    }
    qsort(list,n,sizeof(Point),CompX);

    printf("%.2lf",closestdis(list,n));

    return 0;
}

//
//using namespace std;
//
//int A[5000000];
//
//class sortt{
//private:
//    int n,k;
//public:
//    sortt(int n,int k){
//        this->k=k-1;
//        this->n=n;
//    }
//    void quciksort(){
//        qqsort(A,0,n-1,k);
//    }
//    void qqsort(int A[],int low,int high,int k){
//        int last;
//        if(low==high){
//            printf("%d", A[low]);
//            return;
//        }
//        if(low<high)
//        {
//            last=low;
//
//            for(int i=low+1;i<=high;i++)
//            {
//                if(A[i]>A[low])
//                    swap(A,++last,i);
//                int j=0;
//            }
//
//            swap(A,last,low);
//            if(k==last){
//                printf("%d", A[last]);
//                return;
//            }
//            if(k<last)
//            qqsort(A, low, last - 1, k);
//            if(k>last)
//            qqsort(A, last + 1, high, k);
//        }
//    }
//    void swap(int s[],int i,int j)
//    {
//        int temp;
//        temp=s[i];
//        s[i]=s[j];
//        s[j]=temp;
//    }
//    void show(){
//        printf("%d",A[k]);
//    }
//};
//int main() {
////    int X[10]={7, 3, 5, 1, 4, 2, 6, 8, 34, 457};
//    int kth=0,n=0;
//    scanf("%d %d", &n,&kth);
//    for(int i=0;i<n;i++){
////        A[i]=X[i];
//        scanf("%d", &A[i]);
//    }
//    sortt s= sortt(n,kth);
//    s.quciksort();
////    s.show();
//    return 0;
//}