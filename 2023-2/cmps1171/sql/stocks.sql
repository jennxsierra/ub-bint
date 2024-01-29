-- This table stores my stocks

DROP TABLE IF EXISTS STOCKS;

CREATE TABLE STOCKS(
    ID SERIAL PRIMARY KEY,
    SYMBOL TEXT NOT NULL,
    NUM_SHARES INT,
    DATE_ACQUIRED DATE
);

\copy stocks (symbol, num_shares, date_acquired) FROM './stocks.txt' DELIMITER ',';