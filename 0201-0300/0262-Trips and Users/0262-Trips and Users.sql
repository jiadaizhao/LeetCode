SELECT request_at AS Day, 
       Round(SUM(IF(status != 'completed', 1, 0)) / Count(*), 2) AS 'Cancellation Rate' 
FROM   trips 
WHERE  (request_at BETWEEN '2013-10-01' AND '2013-10-03') 
       AND client_id IN (SELECT users_id 
                         FROM   users 
                         WHERE  banned = 'NO') 
GROUP BY request_at;
