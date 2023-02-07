Approach 3: Sliding Window
Intuition
Can we further reduce the time complexity? The answer is Yes!

Recall how we restart the iteration in approach 2:

If the current fruit at index right makes our window (left, right) have 3 types of fruit, we need to break the iteration over right and start over from index left + 1.

The question is, is this step necessary? Do we need to recalculate the types of fruits from left + 1 again?

If we have found a valid window of size k starting at index left, even though we want to restart at left + 1, there is no need to recalculate the fruit type from left + 1 all to way to right, which represent windows of size no larger than k. We only need to look for windows larger than k!

img

Thus the logic becomes very clear: we let indexes left and right represent the size of the longest valid window we have encountered so far. In further iterations, instead of looking for smaller windows, we just check if the newly added fruit expands the window.

More specifically: we always add fruits from the right side to temporarily increase the window size by 1 (Let's say from k to k + 1), and if the new window is valid, it means that we have managed to find a larger window of size k + 1, great! Otherwise, this means that we haven't encountered a valid window of size k + 1 yet, so we should go back to the previous window size, by removing one fruit from the left side of the window.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Hash map 'basket' to store the types of fruits.
        unordered_map<int, int> basket;
        int left, right;
        
        // Add fruit from the right index (right) of the window.
        for (left = 0, right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove one fruit from the left index (left) of the window.
            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
        }
        
        // Once we finish the iteration, the indexes left and right 
        // stands for the longest valid subarray we encountered.
        return right - left;
    }
};
 
 Complexity Analysis
Let 
�
n be the length of the input array fruits.

Time complexity: O(n)
Space complexity: O(n)

In the worst-case scenario, there might be at most 
O(n) types of fruits inside the window. Take the picture below as an example. Imagine that we have an array of fruits like the following. (The first half is all one kind of fruit, while the second half is n/2 types of fruits)
img 
  
  
  
  
  
  
  
  
  Approach 4: Sliding Window II
Intuition
In the previous approach, we keep the window size non-decreasing. However, we might run into cases where the window contains 

O(n) types of fruits and takes 
O(n) space.

This can be optimized by making sure that there are always at most 2 types of fruits in the window. After adding a new fruit from the right side right, if the current window has more than 2 types of fruit, we keep removing fruits from the left side left until the current window has only 2 types of fruit. Note that the window size may become smaller than before, thus we cannot rely on left and right to keep track of the maximum number of fruits we can collect. Instead, we can just use a variable max_picked to keep track of the maximum window size we encountered.

For the details on the implementation, let's take a look at the following slides.


Algorithm
Initialize max_picked = 0 as the maximum fruits we can collect, and use hash map basket to record the types of fruits in the current window.

Start with an empty window having left = 0 and right = 0 as its left and right index.

We iterate over right and add fruits[right] to this window.

If there are no more than 2 types of fruits, this subarray is valid.
Otherwise, we need to keep removing fruits from the left side until there are only 2 types of fruits in the window.
Then we update max_picked as max(max_picked, right - left + 1).

Once we finish iterating, return max_picked as the maximum number of fruits we can collect.

Implementation
  
  class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // We use a hash map 'basket' to store the number of each type of fruit.
        unordered_map<int, int> basket;
        int left = 0, maxPicked = 0;
        
        // Add fruit from the right index (right) of the window.
        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove fruit from the left index (left) of the window,
            // until the window has only 2 types of fruit.
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            
            // Update maxPicked.
            maxPicked = max(maxPicked, right - left + 1);
        }
        
        // Return maxPicked as the maximum number of fruits we can collect.
        return maxPicked;
    }
};
  
  

Complexity Analysis
n be the length of the input array fruits.

Time complexity: O(n)

Similarly, both indexes left and right are only monotonically increasing during the iteration, thus we have at most 
2⋅n
2⋅n steps,
At each step, we update the hash set by addition or deletion of one fruit, which takes constant time. Note that the number of additions or deletions does not exceed 
Space complexity: O(1)

We maintain the number of fruit types contained in the window in time. Therefore, at any given time, there are at most 3 types of fruits in the window or the hash map basket.
In summary, the space complexity is O(1).

  
  
