#include<iostream>
int main(){for(int i=0;i<10;i++){std::string w;std::cin>>w;int a=1;for(int j=0;j<w.length();j++){if(w[j]=='T'||w[j]=='D'||w[j]=='L'||w[j]=='F')a*=2;}std::cout<<a<<std::endl;}}
