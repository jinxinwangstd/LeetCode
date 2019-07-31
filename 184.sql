SELECT T4.Name AS Department, T3.Name AS Employee, Salary
FROM Employee AS T3 INNER JOIN (SELECT Id, Name, MaxSalary
                                FROM Department AS T1 JOIN (SELECT DepartmentId, MAX(Salary) AS MaxSalary
                                                            FROM Employee
                                                            GROUP BY DepartmentId) AS T2
                                ON T1.Id = T2.DepartmentId) AS T4
ON T3.Salary = T4.MaxSalary AND T3.DepartmentId = T4.Id
