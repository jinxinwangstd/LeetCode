SELECT Email
FROM Person
Group BY Email
HAVING Count(Email) > 1
