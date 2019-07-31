SELECT Name AS Employee
FROM Employee AS T1
WHERE T1.Salary > (SELECT Salary
                   FROM Employee
                   WHERE Id = T1.ManagerId)
