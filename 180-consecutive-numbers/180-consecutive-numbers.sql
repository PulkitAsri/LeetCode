# Write your MySQL query statement below

select distinct l1.num as ConsecutiveNums from logs as l1, logs as l2,  logs as l3 where l2.id=l1.id +1 && l3.id=l2.id+1 && l1.num=l2.num && l2.num=l3.num ;
