SELECT a1.player_id, 
       a1.event_date, 
       SUM(a2.games_played) AS games_played_so_far 
FROM   Activity AS a1 
       INNER JOIN Activity AS a2 
               ON a1.event_date >= a2.event_date 
                  AND a1.player_id = a2.player_id 
GROUP  BY a1.player_id, 
          a1.event_date;
