https://www.geeksforgeeks.org/size-of-the-largest-trees-in-a-forest-formed-by-the-given-graph/

A forest is represented with a hashmap. This hashmap has this key -> value relationship: child -> parent.
Every node has a unique integer element. I needed to find out the largest tree's root node. If there is a tie, return the smallest root.

The tree with the highest number of nodes, is the largest one. The edges are directed from parent to child.

Input:
{{1 -> 2}, {3 -> 4}}

Output:
2