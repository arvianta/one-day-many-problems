-- https://leetcode.com/problems/nth-highest-salary/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT DISTINCT salary
    FROM (
      SELECT
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS salary_rank
      FROM Employee
    ) AS ranked_salaries
    WHERE salary_rank = N
  );
END