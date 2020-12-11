#include <iostream>
#include <chrono>
#include <iomanip>
#include <queue>
using namespace std;



int bfs(int **a,int s, int f, int n){
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i]=-1;
    }
    dist[s]=0;
    queue<int> q;
    q.push(s);
    bool used[n];
    for(int i=0;i<n;i++){
        used[i]=0;
    }
    used[s]=1;
    for(;!q.empty();){
        int v=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(a[v][i]!=0 && !used[i]){
                used[i]=1;
                dist[i]=dist[v]+1;
                q.push(i);
            }
        }
    }
    int res=dist[f];
    return res;
}

int main(){
    freopen("bfs_test.txt", "r", stdin);
    freopen("bfs_result.txt", "w", stdout);
    int n,from,to;
    cin>>n>>from>>to;
    from--;
    to--;
    //int a[n][n];
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) a[i] = (int*)malloc(n*sizeof(int));
    cout<<"in: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
    }
    cout<<endl;
    cout<<"out:";
    auto start = std::chrono::steady_clock::now();
    int res=bfs(a,from,to,n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout<<res;
    cout<<endl;
    cout<<fixed<<setprecision(25)<<"time:"<<diff.count()<<endl;

}
