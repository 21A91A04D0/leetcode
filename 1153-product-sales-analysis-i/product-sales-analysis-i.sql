# Write your MySQL query statement below
select product_name, year, price
From sales
left join product
on product.product_id = sales.product_id;