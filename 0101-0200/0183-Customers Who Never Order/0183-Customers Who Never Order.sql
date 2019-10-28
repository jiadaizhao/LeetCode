SELECT Name Customers
FROM Customers
WHERE Customers.Id NOT IN
(SELECT CustomerId FROM Orders);
