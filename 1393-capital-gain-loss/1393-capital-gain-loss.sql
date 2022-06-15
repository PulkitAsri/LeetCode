# Write your MySQL query statement below

select 
stock_name,
sum(
    case 
        when operation = 'sell' then price
        when operation = 'buy' then -price
        else 0
    end 
) as capital_gain_loss

from stocks group by stock_name order by capital_gain_loss;