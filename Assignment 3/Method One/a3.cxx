#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <iostream>
#include<istream>
#include<fstream>
#include <unordered_map>

using namespace std;

int main(){

// open sample.dat file in read only mode

ifstream infile;

infile.open("input.dat");

string s;

while(infile){

// reading string from file

getline(infile,s);

}

// map to store the frequency of each card

unordered_map<string,int> m;

string res = "";

  for(int i=0;i<s.size();i++){
if(s[i]>'A'&&s[i]<'Z'){
res = res + s[i];
m[res]++;
res = "";
}
else{
res = res + s[i];
}
}

for(auto i:m){
cout<<i.first<<" occurs "<<i.second<<" times " << endl ;
}

return 0;

}