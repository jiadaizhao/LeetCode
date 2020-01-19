SELECT seller_id 
FROM   Sales 
GROUP  BY seller_id 
HAVING Sum(price) = (SELECT Sum(price) 
                     FROM   Sales 
                     GROUP  BY seller_id 
                     ORDER  BY 1 DESC 
                     LIMIT  1);
