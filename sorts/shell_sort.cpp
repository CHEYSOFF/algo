#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;


void sw(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int po (int a, int n) {
	if(n ==0){
		return 1;
	}
	if(n%2==1){
		return po(a, n-1)*a;
	}
	else{
		int b=po(a, n/2);
		return b * b;
	}
}


void shso(int mas[],int n){
    int inc=1;
    for(int i=0;inc*3<n;i++){
        if(i%2==0){
            inc=9*po(2, i)-9*po(2,i/2)+1;
        }
        else{
            inc=8*po(2, i)-6*po(2, (i+1)/2)+1;
        }
        for(int j=inc;j<n;j++){
                int c;
                int a=mas[j];
                for(c=j;c>=inc && mas[c-inc]>a; c-=inc){
                    mas[c]=mas[c-inc];
                }
                mas[c]=a;
        }
    }
}

/*
10
12 12 3 1 89 1 3 4 90 2
*/

int main(){
    freopen("test.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    int n;
    cin>>n;
    int mas[n];
    cout<<"in: ";
    for(int i=0;i<n;i++){
        cin>>mas[i];
        cout<<mas[i]<<" ";
    }
    cout<<endl;
    cout<<"out:";
    auto start = std::chrono::steady_clock::now();
    shso(mas,n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;
    for(int i=0;i<n;i++){
        cout<<mas[i]<<" ";
    }
    cout<<endl;
    cout<<fixed<<setprecision(25)<<"time:"<<diff.count()<<endl;
}
