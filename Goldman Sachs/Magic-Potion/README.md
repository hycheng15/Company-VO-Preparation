Problem Description: Given a string replace the largest repeated substring at every point with an asterisk(*). The goal is end result should be a minimal length string after compression


For example, s = "abcabcd" should become "abc*d", Reason: we know abc has repeated twice, so replace the entire second instance of abc with an *.


and if s = "aabbaabb" it should become "a\*bb\*", Reason: At index 1, a is repeated twice so put an * there, and aabb has repeated twice so replace it's second instance with an *. In this example we don't put an * right after b at index 3 because aab* would represent aabaab, but that isn't the case.

好像不太對 先略過晚點回來想
https://leetcode.com/discuss/interview-question/1030208/goldman-sachs-phone-coderpad-interview-string-compression