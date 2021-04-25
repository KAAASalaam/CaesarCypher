#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


string removeSpecialChars(string s){
  for(int i = 0; i < s.length(); i++){
      if(!isalpha(s[i]) && !isspace(s[i])){
        s = s.erase(i, 1);
        i--;
      }
  }
  return s;
}

char bumpChar(char v, int n){

  v = toupper(v);

  int new_value = 0;

  new_value = int(v)+(n) > int('Z')?int(v)+(n%26)-26:int(v)+n;

  return (char)new_value;

}

string convertString(string s, int n){
   s = removeSpecialChars(s);
   for(int i = 0; i < s.length(); i++){
     if(!isspace(s[i])){
        s[i]=bumpChar(s[i], n);
     }
     
   }
   return s;
}

int main() {

    string val = "";
    int n = 1;

    cout << "Please type message to encode: \n";
    getline(cin, val);
    cout << "Please type number of spaces to increment: \n";
    cin >> n;
    cout << "Your encoded message is: \n";
    cout << convertString(val, n);
    return 0;
}
