-- https://leetcode.com/problems/biggest-single-number/
SELECT COALESCE((
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
    ORDER BY num DESC
    LIMIT 1
), NULL) AS num;
