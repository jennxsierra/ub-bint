-- [CMPS1171-1] Introduction to Databases Final Project
-- Andres Hung & Jennessa Sierra
-- 2024/04/12

/* USAGE */

-- 1. Comment everything after DATABASE SETUP section.
-- 2. Run file as the postgres superuser in the postgres database.
-- 3. Manually log into project database as utopia user.
-- 4. Uncomment the rest of sections and comment the DATABASE SETUP section.
-- 5. Run file again to create the tables and populate with data.

/* DATABASE SETUP */

DROP DATABASE IF EXISTS utopia;
CREATE DATABASE utopia;

DROP ROLE IF EXISTS utopia;
CREATE ROLE utopia WITH LOGIN PASSWORD '#final#';

-- psql@15+ only - grant privileges to utopia user as postgres superuser
\c utopia postgres
GRANT ALL PRIVILEGES ON SCHEMA public TO utopia;
\c utopia utopia

/* CREATE TABLES */

-- drop existing tables
DROP TABLE IF EXISTS user_page_comments CASCADE;
DROP TABLE IF EXISTS user_block_lists CASCADE;
DROP TABLE IF EXISTS user_messages CASCADE;
DROP TABLE IF EXISTS user_conversations CASCADE;
DROP TABLE IF EXISTS user_relationship_preferences CASCADE;
DROP TABLE IF EXISTS relationship_types CASCADE;
DROP TABLE IF EXISTS user_photos CASCADE;
DROP TABLE IF EXISTS user_gender_preferences CASCADE;
DROP TABLE IF EXISTS users CASCADE;
DROP TABLE IF EXISTS genders CASCADE;

-- USERS, GENDERS, and GENDER PREFERENCES

CREATE TABLE genders (
    gender_id SERIAL PRIMARY KEY,
    gender TEXT NOT NULL
);

CREATE TABLE users (
    utopia_id SERIAL PRIMARY KEY,
    username TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL UNIQUE,
    fname TEXT NOT NULL,
    lname TEXT NOT NULL,
    gender INT,
    biography TEXT,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (gender) REFERENCES genders (gender_id)
);

CREATE TABLE user_gender_preferences (
    utopia_id INT,
    gender_id INT,
    PRIMARY KEY (utopia_id, gender_id),
    FOREIGN KEY (utopia_id) REFERENCES users (utopia_id),
    FOREIGN KEY (gender_id) REFERENCES genders (gender_id)
);

-- USER PHOTOS

CREATE TABLE user_photos (
    photo_id SERIAL PRIMARY KEY,
    uploader_id INT,
    url TEXT NOT NULL,
    description TEXT NOT NULL,
    uploaded_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (uploader_id) REFERENCES users (utopia_id)
);

-- RELATIONSHIPS AND RELATIONSHIP PREFERENCES

CREATE TABLE relationship_types (
    relationship_id SERIAL PRIMARY KEY,
    relationship TEXT NOT NULL
);

CREATE TABLE user_relationship_preferences (
    utopia_id INT,
    relationship_id INT,
    PRIMARY KEY (utopia_id, relationship_id),
    FOREIGN KEY (utopia_id) REFERENCES users (utopia_id),
    FOREIGN KEY (relationship_id) REFERENCES relationship_types (relationship_id)
);

-- CONVERSATIONS AND MESSAGES

CREATE TABLE user_conversations (
    conversation_id SERIAL PRIMARY KEY,
    -- assume only 2 users can be in a conversation according to the database specifications
    initiator INT, -- the user who initially started the conversation
    recipient INT, -- the participant user
    -- assume closed conversations cannot be reopened; a new conversation must be created
    active BOOL NOT NULL DEFAULT true, -- users can delete/close conversations; it remains in database but is no longer active
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    closed_at TIMESTAMP DEFAULT NULL,
    FOREIGN KEY (initiator) REFERENCES users (utopia_id),
    FOREIGN KEY (recipient) REFERENCES users (utopia_id)
);

CREATE TABLE user_messages (
    message_id SERIAL PRIMARY KEY,
    conversation_id INT,
    contents TEXT NOT NULL,
    sender INT, -- receiver can be retrieved from sender, conversation_id and the user_conversatinos table
    sent_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    received_at TIMESTAMP NOT NULL, -- when the recipient has gotten the message on their app
    seen_at TIMESTAMP NOT NULL,
    FOREIGN KEY (sender) REFERENCES users (utopia_id),
    FOREIGN KEY (conversation_id) REFERENCES user_conversations (conversation_id)
);

-- USER BLOCK LISTS

CREATE TABLE user_block_lists (
    blocker INT,
    blockee INT,
    PRIMARY KEY (blocker, blockee),
    FOREIGN KEY (blocker) REFERENCES users (utopia_id),
    FOREIGN KEY (blockee) REFERENCES users (utopia_id)
);

-- USER COMMENTS

CREATE TABLE user_page_comments (
    comment_id SERIAL PRIMARY KEY,
    -- assume each user is only allowed one page on which comments are made, so utopia_id is used
    user_page INT,
    commenter INT,
    contents TEXT NOT NULL,
    anonymized BOOL NOT NULL DEFAULT false,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_page) REFERENCES users (utopia_id),
    FOREIGN KEY (commenter) REFERENCES users (utopia_id)
);

/* INSERT DATA */

INSERT INTO genders (gender)
VALUES
    ('male'),
    ('female');

INSERT INTO users (username, email, fname, lname, gender, biography, created_at)
VALUES
    (
        'roylandsumx',
        'roylandsummer@gmail.com',
        'Royland',
        'Summer',
        1,
        'I am a happy-go-lucky nature-loving fellow looking for a date!',
        '2024-01-10 15:52:24.12041-06'
    ),
    (
        'cindyramos',
        'cindylovers@gmail.com',
        'Cindy',
        'Ramos',
        2,
        'I love hiking, adventures and spending my time traveling the world.',
        '2023-10-15 14:20:59.43523-06' -- the last -06 don't change, that's the timezone in BZ
    ),
    (
        'gamer99epic',
        'randallswerve@gmail.com',
        'Randall',
        'Swerve',
        1,
        'Eat, Sleep, Fortnite, Repeat',
        '2024-02-17 02:23:43.75342-06'
    );

INSERT INTO user_gender_preferences (utopia_id, gender_id)
VALUES
    (1, 2),
    (2, 1),
    (3, 2);

INSERT INTO user_photos (uploader_id, url, description, uploaded_at)
VALUES
    (
        1,
        'https://utopiadating.bz/photo/189427',
        'This was me at the September 25th Independence Day celebration in 2023!',
        '2024-01-11 10:12:54.10044-06'
    ),
    (
        2,
        'https://utopiadating.bz/photo/548935',
        'At the Florida beaches relaxing in the sun.',
        '2023-10-15 16:11:04.10234-06' -- make sure this is after user creation date
    );

INSERT INTO relationship_types (relationship)
VALUES
    ('Romance');

INSERT INTO user_relationship_preferences (utopia_id, relationship_id)
VALUES
    (1, 1),
    (2, 1),
    (3, 1);

INSERT INTO user_conversations (initiator, recipient, active, created_at, closed_at)
VALUES
    (1, 2, true, '2024-01-12 09:31:54.87041-06', NULL); -- make sure the times make sense and give some examples of non-active ones with closed_at values

INSERT INTO user_messages (conversation_id, contents, sender, sent_at, received_at, seen_at)
VALUES
    (
        1,
        'hey gurl wats up',
        1,
        '2024-01-12 09:32:03.27141-06',
        '2024-01-12 09:32:05.72341-06',
        '2024-01-12 09:42:04.27051-06'
    ),
    (
        1,
        'Im working (traveling) hbu?',
        2,
        '2024-01-12 09:43:15.45141-06',
        '2024-01-12 09:50:30.34892-06',
        '2024-01-12 09:50:35.29084-06' -- make sure the timings make sense
    );

INSERT INTO user_block_lists (blocker, blockee)
VALUES
    (2, 3);

INSERT INTO user_page_comments (user_page, commenter, contents, anonymized, created_at)
VALUES
    (
        2,
        3,
        'want to play Fortnite?? im the BEST!!1!',
        false,
        '2024-02-17 03:00:14.59840-06'
    );

/* DISPLAY ALL TABLES */

SELECT *
FROM genders;

SELECT *
FROM users;

SELECT *
FROM user_gender_preferences;

SELECT *
FROM user_photos;

SELECT *
FROM relationship_types;

SELECT *
FROM user_relationship_preferences;

SELECT *
FROM user_conversations;

SELECT *
FROM user_messages;

SELECT *
FROM user_block_lists;

SELECT *
FROM user_page_comments;