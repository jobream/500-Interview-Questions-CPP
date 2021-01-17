class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int answer = 0;
        
        while(left < right){
            if(height.at(left) > leftMax) leftMax = height.at(left);
            if(height.at(right) > rightMax) rightMax = height.at(right);
            if(leftMax < rightMax){
                answer += max(0, leftMax - height.at(left));
                left++;
            }else{
                answer += max(0, rightMax - height.at(right));
                right--;
            }
        }
        return answer;
    }
};
