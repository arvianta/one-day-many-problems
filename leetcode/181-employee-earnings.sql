-- https://leetcode.com/problems/employees-earning-more-than-their-managers/
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
ON e.managerId = m.id
WHERE e.Salary > m.Salary;