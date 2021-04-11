SELECT name FROM people
WHERE id IN (SELECT id FROM directors JOIN people ON person_id = id
WHERE movie_id IN (SELECT movie_id FROM ratings WHERE rating >= 9))