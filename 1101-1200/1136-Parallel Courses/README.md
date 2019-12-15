# 1136. Parallel Courses

Difficulty: Hard

https://leetcode.com/problems/parallel-courses/

There are N courses, labelled from 1 to N.

We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.

**Example 1:**  
![ex1](ex1.png)
```
Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.
```

**Example 2:**  
![ex2](ex2.png)
```
Input: N = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: 
No course can be studied because they depend on each other.
```

**Note:**

1. 1 <= N <= 5000
2. 1 <= relations.length <= 5000
3. relations[i][0] != relations[i][1]
4. There are no repeated relations in the input.
