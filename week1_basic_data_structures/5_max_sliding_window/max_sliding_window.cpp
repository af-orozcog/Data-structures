#include <iostream>
#include <vector>
#include<map>

using std::map;
using std::cin;
using std::cout;
using std::vector;
using std::pair;

/*void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}*/


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;
    map<int,int> fr;
    int co = 0;
    for(int i = 0; i < n;++i){
        if(co != w) ++fr[A[i]],++co;
        else{
            --fr[A[i-co]];
            if(fr[A[i-co]] == 0)
                fr.erase(A[i-co]);
            ++fr[A[i]];
        }
        if(co == w)
            printf("%d ",fr.rbegin()->first);
    }
    puts("");
    return 0;
}
