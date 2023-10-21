WITH UserVisits AS (
    SELECT t.visited_on, t.time_spent
    FROM traffic t
    JOIN users u ON t.user_id = u.id
    WHERE u.user_type = 'user'
)

SELECT visited_on, 
       ROUND(AVG(time_spent) OVER (ORDER BY visited_on ROWS BETWEEN 2 PRECEDING AND CURRENT ROW), 4) AS avg_time_spent
FROM UserVisits
ORDER BY visited_on;