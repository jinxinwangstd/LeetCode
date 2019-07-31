SELECT FirstName, LastName, City, State
FROM Person AS T1 LEFT OUTER JOIN Address AS T2
ON T1.PersonId = T2.PersonId
