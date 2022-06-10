# Write your MySQL query statement below
select name as Customers from customers as c left join orders as o on c.id=o.customerId where customerId is NULL;