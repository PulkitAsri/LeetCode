# Write your MySQL query statement below

select max(distinct salary) as SecondHighestSalary from employee where salary != ( select max(distinct salary) from employee);