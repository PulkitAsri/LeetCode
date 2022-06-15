# Write your MySQL query statement below

SELECT
    score,
    DENSE_RANK() OVER (
        ORDER BY score desc
    ) as `rank`
FROM
    scores
order by `rank`;