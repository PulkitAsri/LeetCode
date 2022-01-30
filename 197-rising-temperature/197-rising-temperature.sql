# Write your MySQL query statement below

select W1.id as Id 
from Weather as W1 
join Weather as W2
    where (
        DATEDIFF(w1.recordDate, w2.recordDate)=1 
        and w1.temperature > w2.temperature
    );
