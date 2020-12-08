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
    if(l>=r){
        return;
    }
    int p=a[(l+r)/2];
    int al=l;
    int ar=r;
    for(;;){
        for(;a[al]<p;){
            al++;
        }
        for(;a[ar]>p;){
            ar--;
        }
        if(al>=ar){
            break;
        }
        sw(a[al], a[ar]);
        al++;
        ar--;
    }
    qs(a,l,ar);
    qs(a,ar+1,r);
}
/*
if(l>=r){
        return;
    }
    int p=(l+r)/2;
    int al=l;
    int ar=r;
for(;;){
        for(;a[p]>a[l];){
            l++;
        }
        for(;a[p]<a[r];){
            r--;
        }
        if(l>=r){
            break;
        }
        sw(a[r],a[l]);
        r--;
        l++;
    }
    qs(a,al,r);
    qs(a,r+1,ar);
*/
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
