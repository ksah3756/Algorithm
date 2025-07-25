-- 코드를 입력하세요

SELECT CAR_ID, CAR_TYPE, CC.DAILY_FEE * (1-0.01*CC.DISCOUNT_RATE) * 30 AS FEE
FROM (
    SELECT DISTINCT CRCC.CAR_ID, CRCC.CAR_TYPE, DAILY_FEE, DISCOUNT_RATE
    FROM CAR_RENTAL_COMPANY_CAR CRCC
    ,CAR_RENTAL_COMPANY_RENTAL_HISTORY CRCRH
    ,CAR_RENTAL_COMPANY_DISCOUNT_PLAN CRCD
    WHERE 1=1
    AND CRCC.CAR_ID = CRCRH.CAR_ID
    AND CRCC.CAR_TYPE = CRCD.CAR_TYPE
    AND CRCC.CAR_TYPE IN ('SUV', '세단')
    AND CRCC.CAR_ID NOT IN 
        (SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE ((TO_DATE('2022-11-01', 'YYYY-MM-DD') <= END_DATE AND START_DATE <= TO_DATE('2022-11-30', 'YYYY-MM-DD')))
         )
    AND CRCD.DURATION_TYPE = '30일 이상'
) CC
WHERE CC.DAILY_FEE * (1-0.01*CC.DISCOUNT_RATE) * 30 BETWEEN 500000 AND 2000000
ORDER BY FEE DESC, CAR_TYPE ASC, CAR_ID DESC