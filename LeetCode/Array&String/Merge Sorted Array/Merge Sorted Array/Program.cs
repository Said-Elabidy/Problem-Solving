namespace Merge_Sorted_Array
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] nums1 = new int[] { 1, 2, 3, 0, 0, 0 };
            int[] nums2 = new int[] { 2, 5, 6 };
            int m = 3, n = 3;

            Solution solution = new Solution();
            solution.Merge(nums1, m, nums2, n);

            Console.WriteLine(string.Join(", ", nums1));


        }
    }
}
