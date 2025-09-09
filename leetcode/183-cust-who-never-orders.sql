-- https://leetcode.com/problems/customers-who-never-order/
SELECT name AS Customers 
FROM Customers as c
LEFT JOIN Orders as o
ON c.id = o.CustomerId
WHERE o.id IS NULL;