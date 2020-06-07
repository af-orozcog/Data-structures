#include <iostream>
#include<vector>
#include <string>
#define min(x,y)(x < y? x:y)
using namespace std;

int main() {
    std::string text;
    getline(std::cin, text);

    vector<pair<int,char>> ar;
    bool posi = 1;
    int first = 1000000;
    for (int position = 0; position < text.length() && posi; ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{'){
            ar.push_back({position,next});
            first = min(first,position);
        }
        else if ((next == ')' || next == ']' || next == '}') && ar.size()){
            if(ar.back().second+1 == next || ar.back().second+2 == next) ar.pop_back();
            else {
                printf("%d\n",position+1);
                return 0;
            }
        }
        else if(next == ')' || next == ']' || next == '}'){
            printf("%d\n",position+1);
            return 0;
        }
    }
    if(posi && ((int)ar.size() == 0)) puts("Success");
    else printf("%d\n",ar[0].first+1);
    // Printing answer, write your code here

    return 0;
}
