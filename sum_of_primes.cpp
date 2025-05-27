#include<iostream>
#include<vector>
using namespace std;
bool isprime(int a){
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
void gp(int n,vector<int> &prime){
    int prime1=0;
    int prime2=0;
    for(int i=2;i<=n;i++){
        if(isprime(i)){
            prime.push_back(i);
        }
    }
    int flag=0;
    for(int i=0;i<prime.size();i++){
        for(int j=i;j<prime.size();j++){
            if(prime[i]+prime[j]==n){
                prime1=prime[i];
                prime2=prime[j];
                cout<<n<<" = "<<prime1<<"+"<<prime2<<endl;
                flag=1;
            }
        }
    }
    if(flag==0){
        cout<<n<<" Cannot Expressed as sum of primes";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> prime;
    gp(n,prime);
}