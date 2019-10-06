# Daily Coding Problems

My C++ solutions for the coding-interview-questions provided by [Daily Coding Problem](https://www.dailycodingproblem.com/ "Link to their Site")

Coding Problems Ordered by numbers:

---

**[Coding Problem #1 - [easy]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_001.cpp "Asked by Google - [easy]")**\
This Problem wasy recently asked by _Google_.\
Given a list of numbers and a number k, return wheather any two numberrs from the list add up to ```k```.

For example, given ```[10, 15, 3, 7]``` and ```k = 17```, return true, since ```10 + 7 = 17```.

* [x] Bonus: Can you do this in one pass?

---

**[Coding Problem #2 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_002.cpp "Asked by Uber - [hard]")**\
This problem was asked by _Uber_.\
Given an array of integers, return a new array such that each element at index ```i``` of the new array is the product of all the numbers in the original array except the one at ```i```.

For example, if our input was ```[1, 2, 3, 4, 5]```, the expected output would be ```[120, 60, 40, 30, 24]```. If our input was ```[3, 2, 1]```, the expected output would be ```[2, 3, 6]```.

* [x] Follow-up: what if you can't use division?

---

**[Coding Problem #3 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_003.cpp "Asked by Google - [medium]")**\
This problem was asked by _Google_.\
Given the root to a binary tree, implement ```serialize(root)```, which serializes the tree into a string, and ```deserialize(s)```, which deserializes the string back into the tree.

For example, given the following Node class

```Python
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

* [x] The following test should pass:

```Python
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```

---

**[Coding Problem #4 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_004.cpp "Asked by Stripe - [hard]")**\
This problem was asked by _Stripe_.\
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input ```[3, 4, -1, 1]``` should give ```2```. The input ```[1, 2, 0]``` should give ```3```.
You can modify the input array in-place.

---

**[Coding Problem #5 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_005.cpp "Asked by Jane Street - [medium]")**\
This problem was asked by _Jane Street_.\
 ```cons(a, b)``` constructs a pair and ```car(pair)``` and ```cdr(pair)``` returns the first and last element of that pair. For example, ```car(cons(3, 4))``` returns ```3```, and ```cdr(cons(3, 4))``` returns ```4```.

Given this implementation of cons:

```Python
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
```

Implement ```car``` and ```cdr```.

---

**[Coding Problem #6 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_006.cpp "Asked by Google - [hard]")**\
This problem was asked by _Google_.\
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding nextElement and prevElement fields, it holds a field named both, which is an XOR of the nextElement node and the previous node. Implement an XOR linked list; it has an ```add(node)``` which adds the node to the end, and a ```get(index)``` which returns the node at ```index```.

If using a language that has no pointers (such as Python), you can assume you have access to ```get_pointer``` and ```dereference_pointer``` functions that converts between nodes and memory addresses.

---

**[Coding Problem #7 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_007.cpp "Asked by Facebook - [medium]")**\
This problem was asked by _Facebook_.\
Given the mapping ```a = 1, b = 2, ... z = 26```, and an encoded message, count the number of ways it can be decoded.

For example, the message ```'111'``` would give ```3```, since it could be decoded as ```'aaa'```, ```'ka'```, and ```'ak'```.

You can assume that the messages are decodable. For example, ```'001'``` is not allowed.

---

**[Coding Problem #8 - [easy]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_008.cpp "Asked by Google - [easy]")**\
This problem was asked by _Google_.\
A unival root (which stands for "universal value") is a root where all nodes under it have the same value. Given the root to a binary root, count the number of unival subtrees.

For example, the following root has ```5``` unival subtrees:

```Text
      0
     / \
    1   0
       / \
      1   0
     / \
    1   1
```

---

**[Coding Problem #9 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_009.cpp "Asked by Airbnb - [hard]")**\
This problem was asked by _Airbnb_.\
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, ```[2, 4, 6, 2, 5]``` should return ```13```, since we pick ```2, 6```, and ```5```. ```[5, 1, 1, 5]``` should return ```10```, since we pick ```5``` and ```5```.

* [x] Follow-up: Can you do this in ```O(n)``` time and constant space?

---

**[Coding Problem #10 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_010.cpp "Asked by Apple - [medium]")**\
This problem was asked by _Apple_.\
Implement a job scheduler which takes in a function ```f``` and an integer ```n```, and calls ```f``` after ```n``` milliseconds.

---

**[Coding Problem #11 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_011.cpp "Asked by Twitter - [medium]")**\
This problem was asked by _Twitter_.\
Implement an autocomplete system. That is, given a query string ```s``` and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string ```de``` and the set of strings ```[dog, deer, deal]```, return ```[deer, deal]```.

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

---

**[Coding Problem #12 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_012.cpp "Asked by Amazon - [hard]")**\
This problem was asked by _Amazon_.\
There exists a staircase with ```N``` steps, and you can climb up either ```1 or 2``` steps at a time. Given ```N```, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if ```N``` is ```4```, then there are ```5``` unique ways:

>1, 1, 1, 1\
>2, 1, 1\
>1, 2, 1\
>1, 1, 2\
>2, 2

* [x] What if, instead of being able to climb ```1 or 2``` steps at a time, you could climb any number from a set of positive integers ```X```?\
For example, if ```X = {1, 3, 5}```, you could climb ```1, 3, or 5``` steps at a time.

---

**[Coding Problem #13 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_013.cpp "Asked by Amazon - [hard]")**\
This problem was asked by _Amazon_.\
Given an integer ```k``` and a string ```s```, find the length of the longest substring that contains at most ```k``` distinct characters.

For example, given ```s = "abcba"``` and ```k = 2```, the longest substring with ```k``` distinct characters is ```"bcb"```.

---

**[Coding Problem #14 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_014.cpp "Asked by Google - [medium]")**\
This problem was asked by _Google_.\
The area of a circle is defined as ```πr²```. Estimate ```π``` to 3 decimal places using a Monte Carlo method.

>Hint: The basic equation of a circle is ```x² + y² = r²```.

---

**[Coding Problem #15 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_015.cpp "Asked by Facebook - [medium]")**\
This problem was asked by _Facebook_.\
Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.

---

**[Coding Problem #16 - [easy]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_016.cpp "Asked by Twitter - [easy]")**\
This problem was asked by _Twitter_.\
You run an e-commerce website and want to record the last ```N``` order ids in a log. Implement a data structure to accomplish this, with the following API:

1. ```record(order_id)```: adds the order_id to the log
1. ```get_last(i)```: gets the ith last element from the log. ```i``` is guaranteed to be smaller than or equal to ```N```.

* [x] You should be as efficient with time and space as possible.

---

**[Coding Problem #17 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_017.cpp "Asked by Google - [hard]")**\
This problem was asked by _Google_.\
Suppose we represent our file system by a string in the following manner:

The string ```"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"``` represents:

```plain
dir
 ├── subdir1
 └── subdir2
        └── file.ext
```

The directory ```dir``` contains an empty sub-directory ```subdir1``` and a sub-directory ```subdir2``` containing a file ```file.ext```.

The string ```"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"``` represents:

```plain
dir
 ├── subdir1
 |      ├── file1.ext
 |      └── subsubdir1
 └── subdir2
        └── subsubdir2
                └── file2.ext
```

The directory ```dir``` contains two sub-directories ```subdir1``` and ```subdir2```. ```subdir1``` contains a file ```file1.ext``` and an empty second-level sub-directory ```subsubdir1```. ```subdir2``` contains a second-level sub-directory ```subsubdir2``` containing a file ```file2.ext```.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is ```"dir/subdir2/subsubdir2/file2.ext"```, and its length is ```32``` (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, ```return 0```.

__Note__:

* The name of a file contains at least a period and an extension.
* The name of a directory or sub-directory will not contain a period.

---

**[Coding Problem #18 - [hard]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_018.cpp "Asked by Google - [hard]")**\
This problem was asked by _Google_.\
Given an array of integers and a number ```k```, where ```1 <= k <= length of the array```, compute the maximum values of each subarray of length ```k```.

For example, given ```array = [10, 5, 2, 7, 8, 7]``` and ```k = 3```, we should get: ```[10, 7, 8, 8]```, since:

* ```10 = max(10, 5, 2)```
* ```7 = max(5, 2, 7)```
* ```8 = max(2, 7, 8)```
* ```8 = max(7, 8, 7)```

1. [x] Do this in ```O(n)``` time and ```O(k)``` space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

---

**[Coding Problem #19 - [medium]](https://github.com/BlueQuote/Daily_Coding_Problems/blob/master/Problems_0-100/Daily_Coding_Problem_019.cpp "Asked by Facebook - [medium]")**\
This problem was asked by _Facebook_.\
A builder is looking to build a row of ```N``` houses that can be of ```K``` different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
Given an ```N``` by ```K``` matrix where the ```n-th``` row and ```k-th``` column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.

---
