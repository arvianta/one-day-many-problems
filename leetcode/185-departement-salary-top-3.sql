-- https://leetcode.com/problems/department-top-three-salaries/
SELECT d.name AS Department, 
    e.name AS Employee, 
    e.salary AS Salary
FROM Employee as e
JOIN Department as d
    ON e.departmentId = d.id
WHERE e.salary IN (
    SELECT salary
    FROM (
        SELECT DISTINCT e2.salary
        FROM Employee e2
        WHERE e2.DepartmentId = e.DepartmentId
        ORDER BY e2.salary DESC
        LIMIT 3 
    ) tmp
);