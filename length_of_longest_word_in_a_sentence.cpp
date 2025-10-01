#include<bits/stdc++.h>
using namespace std;
int main(){
    string sentence;
    cout<<"enter the sentence"<<endl;
    getline(cin,sentence);
    stringstream ss(sentence);
    string word;
    int length=0;
    while(ss>>word){
        if(word.length()>length){
            length=word.length();
        }

    }
    cout<<length;
}