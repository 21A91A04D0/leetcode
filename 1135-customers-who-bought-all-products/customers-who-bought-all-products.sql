# Write your MySQL query statement below
select customer_id
from customer 
group by customer_id
having (select count(product_key)
from product) = count(distinct product_key)



