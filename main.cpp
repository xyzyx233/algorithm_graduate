#include <iostream>
#include <string.h>

using namespace std;

int A[5000000];

class sortt{
private:
    int n,k;
public:
    sortt(int n,int k,int* Aa){
//        memset(A,0,sizeof(int)*5000000);
        this->k=k;
        this->n=n;
        for(int i=0;i<n;i++){
            A[i]=Aa[i];
        }
    }
    int kthmax(){
        return  0;
    }
    void quciksort(){
        qqsort(A,0,n-1,k);
    }
    void qqsort(int A[],int low,int high,int k){
        int last;
        if(low<high)    //当数组中的元素个数大于1时，才进行操作
        {
            last=low;   //选取第一个元素作为基准
            //把小于基准元与大于基准元的分开，last记录它们分开的界限
            for(int i=low+1;i<=high;i++)
            {
                if(A[i]<A[low])
                    swap(A,++last,i);
            }

            swap(A,last,low);//基准元与界限交换，这样的话，基准元两边就是一边大于，一边小于；
            if(k!=0){
                qqsort(A,low,last-1,k);  //对左区间递归排序
            }else{
                qqsort(A,last+1,high,k);//对右区间递归排序
            }
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
        cout << A[k] << endl;
        for(int i=0;i<n;i++){
            cout << A[i] << ' ';
        }
        cout << endl;
    }
};
int main() {
    int X[5]={1,4,3,2,5};
    sortt s= sortt(5,2,X);
    s.quciksort();
    s.show();
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}