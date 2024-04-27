# Write your MySQL query statement below
SELECT product.product_name, sales.year, sales.price
FROM Product
CROSS JOIN sales
ON sales.product_id = product.product_id;