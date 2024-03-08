class Solution {
public:
    int maxProduct(vector<int>& nums) {
         deque<int> deq;
    int lock = 0, sum = -1000, co = 0, ans = 0, a = 0, b = 0, c = 0, d = 0;
    int n, m, k, mx = -1000;
    int fir = 0, sec = 0, x = 0, y = 0, point, in, temp; 
        
        for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        deq.push_back(nums[i]);
        if (sum == -1000)
          sum = 1;
        sum *= nums[i];
        mx = max(mx, sum);
      }
      if (nums[i] == 0 || i+1 == nums.size()) {
        cout << sum << endl;
        while (deq.size() > 1) {
          sum /= deq.front();
          //cout << sum << " " << deq.front() << endl;
          mx = max(mx, sum);
          deq.pop_front();
        }
          if(deq.size()>0)
        deq.pop_front();
      //  mx = max(mx, sum);
        if (nums[i] == 0)
          mx = max(mx, (int)0);
        sum = -1000;

        //mx = max(mx, sum);
      }
    }
    return mx;
    }
};