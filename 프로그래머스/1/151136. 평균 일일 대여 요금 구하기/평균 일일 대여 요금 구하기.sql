-- 코드를 입력하세요
SELECT
    ROUND(AVG(cc.DAILY_FEE), 0) AS AVERAGE_FEE
FROM
    CAR_RENTAL_COMPANY_CAR cc
WHERE
    cc.CAR_TYPE = 'SUV';
