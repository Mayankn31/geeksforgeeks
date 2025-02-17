class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int>pq;
        for(int x:arr) pq.push(x);
        vector<int>res;
        while(k--){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
