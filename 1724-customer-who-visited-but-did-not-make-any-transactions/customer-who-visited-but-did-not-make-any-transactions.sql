# Write your MySQL query statement below
select customer_id, count(customer_id) as count_no_trans
FROM visits
LEFT JOIN transactions
on visits.visit_id = transactions.visit_id
WHERE Transactions.transaction_id IS NULL
group by customer_id
order by count_no_trans desc;