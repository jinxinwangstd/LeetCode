SELECT Score, (SELECT COUNT(DISTINCT Score)
               FROM Scores
               WHERE Score >= T1.Score) AS Rank
FROM Scores AS T1
ORDER BY Score DESC
