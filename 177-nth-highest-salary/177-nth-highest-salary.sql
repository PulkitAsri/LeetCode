CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n=n-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary from Employee order by salary desc limit n,1
     # SYNTAX- limit [offset], rownumber
  );
END