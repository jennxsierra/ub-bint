-- An INNER JOIN returs a row if the row matches in all tables
SELECT
    S.student_id,
    S.first_name,
    S.last_name,
    G.student_id,
    G.grade
FROM
    students AS S
    INNER JOIN grades AS G ON S.student_id = G.student_id;

-- A LEFT OUTER JOIN determines what is in the first table but not the second
SELECT
    S.student_id,
    S.first_name,
    S.last_name,
    G.student_id,
    G.grade
FROM
    students AS S
    LEFT OUTER JOIN grades AS G ON S.student_id = G.student_id
WHERE
    G.student_id IS NULL;