-- https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(*) = (
    SELECT MAX(order_count)
    FROM (
        SELECT COUNT(*) AS order_count
        FROM Orders
        GROUP BY customer_number
    ) AS t
);