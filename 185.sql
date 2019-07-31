SELECT T1.Name AS Department, T2.Name AS Employee, Salary
FROM Department AS T1 JOIN (SELECT *
                            FROM Employee AS T3
                            WHERE (SELECT COUNT(DISTINCT Salary)
                                   FROM Employee AS T4
                                   WHERE T3.Salary <= T4.Salary
                                   AND T3.DepartmentId = T4.DepartmentId) <= 3) AS T2
ON T1.Id = T2.DepartmentId
