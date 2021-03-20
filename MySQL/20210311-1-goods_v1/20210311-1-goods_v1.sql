select * from goods_v1.goods INTO OUTFILE 'C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\\backup.sql';
SET SQL_SAFE_UPDATES=0;
delete from goods_v1.goods;
LOAD DATA INFILE 'C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\\backup.sql' INTO TABLE goods_v1.goods;
select * from goods_v1.goods;