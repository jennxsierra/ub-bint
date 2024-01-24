DROP TABLE IF EXISTS stocks;

CREATE TABLE stocks(
    id SERIAL PRIMARY KEY,
    symbol TEXT NOT NULL,
    num_shares INT,
    date_acquired DATE
);

\copy stocks (symbol, num_shares, date_acquired) FROM './stocks.txt' DELIMITER ',';