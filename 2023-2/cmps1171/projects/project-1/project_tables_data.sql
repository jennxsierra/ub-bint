-- [CMPS1171-1] Introduction to Databases Project 1
-- Andres Hung & Jennessa Sierra
-- 2024/02/23

/* USAGE */

-- 1. Comment everything after DATABASE SETUP section.
-- 2. Run file as the postgres superuser in the postgres database.
-- 3. Manually log into music database as music user.
-- 4. Uncomment the rest of sections and comment the DATABASE SETUP section.
-- 5. Run file again to create the tables and populate with data.

/* DATABASE SETUP */

DROP DATABASE IF EXISTS music;
CREATE DATABASE music;

DROP ROLE IF EXISTS music;
CREATE ROLE music WITH LOGIN PASSWORD '$swordfish$';

-- psql@16 only - grant privileges to music user as postgres superuser
-- \c music
-- GRANT ALL PRIVILEGES ON SCHEMA public TO music;
-- \c music music

/* CREATE TABLES */

-- clear existing tables
DROP TABLE IF EXISTS performances CASCADE;
DROP TABLE IF EXISTS districts CASCADE;
DROP TABLE IF EXISTS shows CASCADE;
DROP TABLE IF EXISTS venues;
DROP TABLE IF EXISTS artists;

-- used in both artist and venue addresses
CREATE TABLE
    districts (
        district_id SERIAL PRIMARY KEY,
        name TEXT NOT NULL
    );

CREATE TABLE
    artists (
        artist_id SERIAL PRIMARY KEY,
        first_name TEXT NOT NULL,
        last_name TEXT NOT NULL,
        gender CHAR(1) NOT NULL CHECK (gender in ('m', 'f', 'o')),
        date_of_birth DATE NOT NULL,
        genre TEXT NOT NULL, -- assume one genre
        address TEXT NOT NULL, -- assume one address
        district INT,
        phone TEXT NOT NULL, -- assume one phone number
        email TEXT, -- assume one email address
        FOREIGN KEY (district) REFERENCES districts (district_id)
    );

CREATE TABLE
    venues (
        venue_id SERIAL PRIMARY KEY,
        name TEXT NOT NULL,
        address TEXT NOT NULL,
        district INT,
        capacity INT NOT NULL,
        private BOOL NOT NULL,
        contact_phone TEXT NOT NULL,
        FOREIGN KEY (district) REFERENCES districts (district_id)
    );

CREATE TABLE
    shows (
        show_id SERIAL PRIMARY KEY,
        name TEXT NOT NULL,
        venue INT,
        start_date DATE NOT NULL,
        end_date DATE NOT NULL,
        price NUMERIC(9, 2) NOT NULL,
        description TEXT NOT NULL,
        tickets INT NOT NULL,
        vip_tickets INT,
        FOREIGN KEY (venue) REFERENCES venues (venue_id)
    );

-- linking table to indicate many-to-many relationship between artists and shows tables
CREATE TABLE
    performances (
        performance_id SERIAL PRIMARY KEY,
        show_id INT,
        artist_id INT,
        FOREIGN KEY (show_id) REFERENCES shows (show_id),
        FOREIGN KEY (artist_id) REFERENCES artists (artist_id)
    );

/* INSERT DATA INTO TABLES */

INSERT INTO districts (name)
VALUES
    ('Corozal'),
    ('Orange Walk'),
    ('Belize'),
    ('Cayo'),
    ('Stann Creek'),
    ('Toledo');

INSERT INTO artists (first_name, last_name, gender, date_of_birth, genre, address, district, phone, email)
VALUES
    ('John', 'Smith', 'm', '2000-01-01', 'Country', '14 Apple Street', 4, '633-1902', 'johnsmith@gmail.com'),
    ('Jane', 'Smith', 'f', '2001-02-10', 'Pop', '34 Mango Street', 1, '633-7787', 'janesmith@gmail.com');

INSERT INTO venues (name, address, district, capacity, private, contact_phone)
VALUES
    ('Bliss Institute of Arts', 'Seaside Avenue', 3, 1000, false, '822-0989');

INSERT INTO shows (name, venue, start_date, end_date, price, description, tickets, vip_tickets)
VALUES
    ('Summer Crash', 1, '2023-06-01', '2023-06-03', 50000.00, 'A summer fun event.', 500, 50);

INSERT INTO performances (show_id, artist_id)
VALUES
    (1, 1),
    (1, 2);