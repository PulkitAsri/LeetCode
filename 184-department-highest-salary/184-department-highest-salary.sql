# Write your MySQL query statement below


select d.name as `Department`, e.name as `Employee`, e.salary as `Salary` from employee as e,

(select max(salary) as maxSalary, departmentId as did from employee group by departmentId) as mx,
department as d

where e.departmentId= d.id and e.salary=mx.maxSalary  and e.departmentId=mx.did





; 