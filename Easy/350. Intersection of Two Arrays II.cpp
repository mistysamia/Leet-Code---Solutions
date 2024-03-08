class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int,vector<int>, greater<int>> deq1,deq2;
        vector<int>ans;

        for(int i=0;i<nums1.size();i++){
            deq1.push(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++){
            deq2.push(nums2[i]);
        }

        while(!deq1.empty() && !deq2.empty()){

            while(!deq1.empty() && deq1.top()< deq2.top()){
                deq1.pop();
            }

            while(!deq2.empty() && deq1.top()> deq2.top()){
                deq2.pop();
            }

            while(!deq1.empty() && !deq2.empty() && deq1.top()==deq2.top()){
                ans.push_back(deq1.top());
                deq1.pop();
                deq2.pop();
            }

        }
        return ans;
    }
};