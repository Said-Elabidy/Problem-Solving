namespace Remove_Duplicates_From_Sorted_Array
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] ints = { 1, 1, 2, 2, 3, 4 };

            Solution solution = new Solution();

            int newLength = solution.RemoveDuplicates(ints);

            Console.WriteLine("New length: " + newLength);

            Console.Write($"Modified array: ");
            foreach (var item in ints)
            {
                Console.Write(item + " ");
            }
        }
    }
}
