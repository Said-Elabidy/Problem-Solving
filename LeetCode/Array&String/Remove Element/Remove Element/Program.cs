namespace Remove_Element
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[] { 3, 2, 2, 3 };
            int valToRemove = 3;

            Solution solution = new Solution();
            int newLength = solution.RemoveElement(nums, valToRemove);

            // Print only the valid elements (from index 0 to newLength - 1)
            Console.WriteLine("New Length: " + newLength);
            Console.WriteLine("Modified Array: " + string.Join(", ", nums.Take(newLength)));
        }
    }
}
