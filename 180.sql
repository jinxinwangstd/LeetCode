SELECT DISTINCT Num AS ConsecutiveNums
FROM Logs AS T1
WHERE Num = (SELECT Num
             FROM Logs
             WHERE Id = T1.Id + 1)
AND   NUM = (SELECT Num
             From Logs
             WHERE Id = T1.Id + 2)
