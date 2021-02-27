#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; 
using std::string; 
using std::vector; 
using std::cin; 

int main() {
    
    string str;
    vector<string> v;
        
    while(cin >> str) {
        v.push_back(str);
    }
    
    auto pos1 = find(v.begin(), v.end(), "begin");
    auto pos2 = find(v.begin(), v.end(), "end");
    
    vector<string> result(v.size());  
   
    if(pos1 != v.end()) {     
        ++pos1;   
        copy(pos1, pos2, result.begin());
    }
 
    for(auto iterations = result.begin(); iterations != result.end(); iterations++) {
        cout << *iterations << " ";
    }

    cout << "\n";
    
    return 0;
}
