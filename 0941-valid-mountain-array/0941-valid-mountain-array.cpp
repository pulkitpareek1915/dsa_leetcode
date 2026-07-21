class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
         int flag1 = 0, flag2 = 0;
        if(arr.size() < 3){
            return false;
        }
        int i = 1;
        while(i < arr.size() && arr[i] > arr[i-1]){
            i++;
            flag1 = 1;
        }
        while(i < arr.size() && arr[i] < arr[i-1]){
            i++;
            flag2 = 1;

        }
        if(i == arr.size() && (flag1 + flag2) == 2){
            return true;
        }
        return false;
    }
};