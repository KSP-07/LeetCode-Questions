
/*
PROBLEM:
You’re given a string 
�
S of length 
�
N. In one move, you can replace one of its characters with any other lowercase Latin letter.
Find the minimum number of moves required to make 
�
S an anti-palindrome, i.e, no rearrangement of 
�
S is a palindrome.

EXPLANATION:
First, let’s check whether 
�
S is itself an anti-palindrome, in which case the answer will be 
0
0.

To do this, we need to check whether 
�
S can be rearranged into a palindrome.
Checking for this is somewhat well-known, and can be done as follows:

If 
�
N is even, then 
�
S can be rearranged to form a palindrome if and only if every character appears an even number of times.
If 
�
N is odd, 
�
S can be rearranged to form a palindrome if and only if exactly one character appears an odd number of times; and everything else appears an even number of times.
 Proof
So, check if 
�
S satisfies the respective condition for its parity; if it doesn’t, the answer is of course 
0
0.

What about the case when 
�
S does satisfy those conditions, i.e, can be rearranged into a palindrome?

Let’s analyze what we can change.

If 
�
N is even, we know every character occurs an even number of times.
just replace any character of 
�
S with any other character; and both the new and the old character will now have an odd frequency.
So, the answer in this case is 
1
1
If 
�
N is odd, we need slightly more casework.
Exactly one character has an odd frequency; let it be 
�
α. Then,
If 
�
S has some character that’s not 
�
α, then one move is enough.
Replace a non-
�
α character with another different non-
�
α character, now there are three characters with odd occurrences.
If 
�
S consists of only the letter 
�
α repeated 
�
N times, the answer is 
2
2: replacing one occurrence of 
�
α with something else isn’t enough (since the new character will have odd frequency but 
�
α will be even).
However, after one replacement we’ll be back in the first case; and from there we know the answer is 
1
1.
Putting it together, we have the following cases:

If 
�
S is already an anti-palindrome, the answer is 
0
0.
Otherwise,
If 
�
N is even, the answer is 
1
1.
If 
�
N is odd and 
�
S contains at least two distinct characters, the answer is 
1
1.
Else, the answer is 
2
2.
TIME COMPLEXITY
�
(
�
)
O(N) per test case.

CODE:
 Editorialist's code (Python)
from collections import Counter
for _ in range(int(input())):
    n = int(input())
    s = input()
    freq = Counter(s)
    odds = 0
    for x in freq.values(): odds += x%2
    if n%2 == 0:
        if odds == 0: print(1)
        else: print(0)
    else:
        if len(freq) == 1: print(2)
        elif odds == 1: print(1)
        else: print(0)


*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n ;
	    cin>>n;
	    string str;
	    cin>>str;
	    
	    unordered_map<char , int> mp;
	    int cnt =0;
	    for(auto i : str){
	        mp[i]++;
	    }
	    for(auto i :mp){
	        if(i.second%2 != 0) cnt++;
	    }
	    
	    if(n%2 == 0) {
	        if(cnt == 0){
	            cout<<1<<endl;
	        }
	        else{
	            cout<<0<<endl;
	        }
	    }
	    else{
	        if(mp.size() == 1) cout<<2<<endl;
	        else if(cnt == 1) cout<<1<<endl;
	        else cout<<0<<endl;
	    }
	    
	}
	return 0;
}
