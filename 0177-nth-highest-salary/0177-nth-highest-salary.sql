CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        select distinct salary from Employee e1 where N=(
            select count(distinct(e2.salary))
            from Employee e2
            where e1.salary<=e2.salary
        )
  );
END