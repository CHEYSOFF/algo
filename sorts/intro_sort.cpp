#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;

void sw(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void build(int a[],int n, int i){
    int maind;
    bool bo=1;
    for(;i*2<=n && bo==1;){
        if(i*2==n){
            maind=n;
        }
        else if(a[i*2]>a[i*2+1]){
            maind=i*2;
        }
        else{
            maind=2*i+1;
        }
        if(a[i]<a[maind]){
            sw(a[i], a[maind]);
            i=maind;
        }
        else{
            bo=0;
        }
    }
}

void hs(int a[], int n){
    for(int i=n/2-1;i>=0;i--){
        build(a,n-1,i);
    }
    for(int i=n-1;i>=1;i--){
        sw(a[i],a[0]);
        build(a,i-1,0);
    }
}

void is(int a[], int l, int r, int m_d,int n){
    if(m_d=1){
        hs(a,n);
        return;
    }
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
    is(a,l,ar,m_d-1,n);
    is(a,ar+1,r,m_d-1,n);
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
    int m_d=floor(2*log(n));
    auto start = std::chrono::steady_clock::now();
    is(a,0,n,m_d,n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<fixed<<setprecision(25)<<"time:"<<diff.count()<<endl;

}
