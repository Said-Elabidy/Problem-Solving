namespace Remove_Duplicates_From_Sorted_Array
{
    internal class Solution
    {// [1 ,1 , 2, 2, 3, 4] -> [1, 2, 3, 4]
        public int RemoveDuplicates(int[] nums)
        {
            if (nums.Length == 0) return 0;

            int i = 0;

            for (int j = 1; j < nums.Length; j++)
            {
                if (nums[j] != nums[i])
                {
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i + 1;
        }

    }
}
