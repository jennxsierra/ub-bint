-- [CMPS1171-1] Introduction to Databases Project 2
-- Andres Hung & Jennessa Sierra
-- 2024/03/22

/* USAGE */

-- 1. Comment everything after DATABASE SETUP section.
-- 2. Run file as the postgres superuser in the postgres database.
-- 3. Manually log into project database as project user.
-- 4. Uncomment the rest of sections and comment the DATABASE SETUP section.
-- 5. Run file again to create the tables and populate with data.

/* DATABASE SETUP */

DROP DATABASE IF EXISTS project;
CREATE DATABASE project;

DROP ROLE IF EXISTS project;
CREATE ROLE project WITH LOGIN PASSWORD '#swordfish#';

-- psql@16 only - grant privileges to project user as postgres superuser
\c project
GRANT ALL PRIVILEGES ON SCHEMA public TO project;
\c project project

/* CREATE TABLES */

-- drop existing tables
DROP TABLE IF EXISTS student_parent CASCADE;
DROP TABLE IF EXISTS students CASCADE;
DROP TABLE IF EXISTS parents CASCADE;
DROP TABLE IF EXISTS classrooms CASCADE;
DROP TABLE IF EXISTS buildings CASCADE;
DROP TABLE IF EXISTS teachers CASCADE;

CREATE TABLE buildings (
    building_id SERIAL PRIMARY KEY,
    name TEXT NOT NULL
);

CREATE TABLE classrooms (
    classroom_id SERIAL PRIMARY KEY,
    name TEXT NOT NULL,
    building INT NOT NULL,
    FOREIGN KEY (building) REFERENCES buildings (building_id)
);

CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    date_of_birth DATE NOT NULL,
    address TEXT NOT NULL,
    classroom INT NOT NULL,
    FOREIGN KEY (classroom) REFERENCES classrooms (classroom_id)
);

CREATE TABLE parents (
    parent_id SERIAL PRIMARY KEY,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    address TEXT NOT NULL,
    phone TEXT NOT NULL
);

CREATE TABLE teachers (
    teacher_id SERIAL PRIMARY KEY,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    address TEXT NOT NULL,
    phone TEXT NOT NULL
);

-- linking table to indicate many-to-many relationship between students and parents
CREATE TABLE student_parent (
    student_id INT NOT NULL,
    parent_id INT NOT NULL,
    PRIMARY KEY (student_id, parent_id),
    FOREIGN KEY (student_id) REFERENCES students (student_id),
    FOREIGN KEY (parent_id) REFERENCES parents (parent_id)
);

/* INSERT DATA */

INSERT INTO buildings (name)
VALUES
    ('George Price'),
    ('Dean Barrow');

INSERT INTO classrooms (name, building)
VALUES
    ('Toucan', 1),
    ('Tapir', 1),
    ('Mahogany', 2),
    ('Black Orchid', 2);

INSERT INTO students (first_name, last_name, date_of_birth, address, classroom)
VALUES
    ('Miguel', 'Vasquez', '2018-05-15', '26 Canada Hill St, Belmopan', 1),
    ('Maria', 'Guerrero', '2017-11-20', '45 Orange St, Belmopan', 2),
    ('Michael', 'Flowers', '2019-03-10', '17 Hibiscus St, Belmopan', 3),
    ('Sandra', 'Castillo', '2018-09-25', '9 Unity Blvd, Belmopan', 4),
    ('David', 'Brown', '2017-07-01', '13 Toucan Ave, Belmopan', 1),
    ('Martha', 'Reyes', '2019-12-12', '11 Power Ln, Belmopan', 2),
    ('Daniel', 'Garcia', '2018-02-28', '15 Trinity Blvd, Belmopan', 3),
    ('Olivia', 'Young', '2019-06-18', '19 Constitution Dr, Belmopan', 4),
    ('Matthew', 'Neal', '2017-10-05', '24 Tapir Ave, Belmopan', 1),
    ('Sophia', 'Usher', '2018-08-22', '46 Mayflower St, Belmopan', 2);

INSERT INTO parents (first_name, last_name, address, phone)
VALUES
    ('Jorge', 'Vasquez', '26 Canada Hill St, Belmopan', '555-1234'),
    ('Alissa', 'Guerrero', '45 Orange St, Belmopan', '555-5678'),
    ('Thomas', 'Flowers', '17 Hibiscus St, Belmopan', '555-9012'),
    ('Karen', 'Castillo', '9 Unity Blvd, Belmopan', '555-3456'),
    ('Frank', 'Brown', '13 Toucan Ave, Belmopan', '555-7890'),
    ('Lisa', 'Reyes', '32 Power Ln, Belmopan', '555-2345'),
    ('Julio', 'Garcia', '15 Trinity Blvd, Belmopan', '555-6789'),
    ('Janet', 'Young', '19 Constitution Dr, Belmopan', '555-0123'),
    ('Albert', 'Neal', '24 Tapir Ave, Belmopan', '555-4567'),
    ('Ruth', 'Usher', '46 Mayflower St, Belmopan', '555-8901');

INSERT INTO teachers (first_name, last_name, address, phone)
VALUES
    ('Kieran', 'Ryan', '78 Trinity Blvd, Belmopan', '555-2468'),
    ('David', 'Garcia', '45 Cardinal Ave, Belmopan', '555-1357'),
    ('Vernelle', 'Sylvester', '12 Tiger Ave, Belmopan', '555-9630'),
    ('Amilcar', 'Umana', '19 Power Ln, Belmopan', '555-7421'),
    ('Manuel', 'Medina', '65 Trio St, Belmopan', '555-8532'),
    ('Stephen', 'Sangster', '32 Forest Dr, Belmopan', '555-6974'),
    ('Josue', 'Ake', '15 Flowers St, Belmopan', '555-3815'),
    ('Apolonio', 'Aguilar', '29 Macal St, Belmopan', '555-2697'),
    ('Steven', 'Lewis', '24 Macaw Ave, Belmopan', '555-1548'),
    ('Giovanni', 'Pinelo', '46 College Blvd, Belmopan', '555-9637');

INSERT INTO student_parent (student_id, parent_id)
VALUES
    (1, 1), (1, 2),
    (2, 3), (2, 4),
    (3, 5), (3, 6),
    (4, 7), (4, 8),
    (5, 9), (5, 10),
    (6, 1), (6, 2),
    (7, 3), (7, 4),
    (8, 5), (8, 6),
    (9, 7), (9, 8),
    (10, 9), (10, 10);