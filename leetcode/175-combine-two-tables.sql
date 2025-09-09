-- https://leetcode.com/problems/combine-two-tables/
SELECT firstName, lastName, city, state
FROM Person as P
LEFT JOIN Address as A ON P.personId = A.personId;