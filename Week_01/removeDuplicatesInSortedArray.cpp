    int removeDuplicates(vector<int>& nums) {
        //检查数组是否为空
        if (nums.size() == 0) 
            return 0;

        //引入双指针
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { //若为不同元素
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1; //返回数组中唯一元素的总个数
    }