#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

void sw(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void qs(int a[], int l, int r){
    int al=l;
    int ar=r;
    int p=(l+r)/2;
    for(;;){
        for(;a[p]>a[l];){
            l++;
        }
        for(;a[p]<a[r];){
            r--;
        }
        if(r<l){
            break;
        }
        sw(a[r],a[l]);
        r--;
        l++;
    }
    if(al<r){
        qs(a,al,r);
    }
    if(ar>l){
        qs(a,l,ar);
    }
}
/*
10
5 7 8 4 3 5 2 6 4 5
*/
int main(){
    freopen("test.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    cout<<"in: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"out:";
    auto start = std::chrono::steady_clock::now();
    qs(a,0,n-1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<fixed<<setprecision(25)<<"time:"<<diff.count()<<endl;

}
