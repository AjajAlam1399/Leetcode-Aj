# Write your MySQL query statement below
SELECT Q1.stock_name , Q1.sell_price -Q2.buy_price as capital_gain_loss FROM (SELECT stock_name , sum(price) as sell_price FROM Stocks WHERE operation="Sell"
GROUP BY stock_name) Q1
JOIN
(SELECT stock_name , sum(price) as buy_price FROM Stocks WHERE operation="Buy"
GROUP BY stock_name ) Q2
ON Q1.stock_name=Q2.stock_name;