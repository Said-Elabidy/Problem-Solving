using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Remove_Element
{
    public class Solution
    {
        public int RemoveElement(int[] nums, int val)
        {
            int counter = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != val)
                {
                    counter++;
                }

            }

            int[] ints =new int[counter] ;
            int c = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                
                if (nums[i] != val)
                {
                    ints[c] = nums[i];
                    c++;
                }

            }
            ints.CopyTo(nums,0);

            return ints.Length;


        }

    }

}