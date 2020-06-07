#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
#define max(x,y)(x > y?x:y)
using namespace std;

int nums[100000];
int dp[100000];

int dfs(int t){
    if(dp[t] != -1) return dp[t];
    if(nums[t] == -1) return 1;
    return (dp[t] = dfs(nums[t])+1);
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i){
        dp[i] = -1;
        int va;scanf(" %d",&va);
        nums[i] = va;
    }
    int ans = 0;
    for(int i = 0; i < n;++i)
        ans = max(ans,dfs(i));
    printf("%d\n",ans);
    return 0;
}
