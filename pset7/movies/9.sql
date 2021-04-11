SELECT name FROM people 
WHERE id IN (SELECT DISTINCT id
FROM stars JOIN people ON person_id = id
WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004))
ORDER BY birth