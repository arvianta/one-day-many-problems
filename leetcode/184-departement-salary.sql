-- https://leetcode.com/problems/department-highest-salary/
SELECT d.name AS Department, 
    e.name AS Employee, 
    e.salary AS Salary
FROM Employee as e
JOIN Department as d
    ON e.departmentId = d.id
WHERE e.salary = (
    SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.DepartmentId = e.DepartmentId
);