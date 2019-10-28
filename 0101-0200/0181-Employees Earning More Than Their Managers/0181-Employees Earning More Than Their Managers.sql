SELECT a.NAME Employee
FROM Employee a
JOIN Employee b
ON a.ManagerId = b.Id
AND a.Salary > b.Salary;
