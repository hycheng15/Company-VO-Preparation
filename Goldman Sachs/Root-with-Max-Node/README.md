// https://leetcode.com/discuss/interview-question/6023404/Goldman-Sachs-or-Coderpad-or-Software-Engineer-Associate

Find the root with max nodes in disjoint graphs(trees).
A forest is represented with a hashmap. This hashmap has this relationship
key -> value :: child -> parent
We need to find out the largest tree's root node. In-case of a tie, return the smaller root value.


Eg:
Input:
{{1 -> 2}, {3 -> 4}}
Output:
2