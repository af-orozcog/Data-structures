#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<pair<long long,long long>> q;
    for(int i = 0; i < num_workers_;++i) q.push({0,-i});
    for(int i = 0; i < jobs_.size();++i){
        pair<long long,long long> to = q.top();
        to.first *= (long long)-1;
        to.second *= (long long)-1;
        q.pop();
        assigned_workers_[i] = to.second;
        start_times_[i] = to.first;
        q.push({-(to.first+(long long)jobs_[i]),-to.second});
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
