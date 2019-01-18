CREATE DATABASE test

CREATE TABLE book (
   BookNO int PRIMARY KEY,
   BookName varchar(50) NOT NULL,
   Author varchar(50) ,
   Publishment varchar(50),
   ButTime varchar(50) ,
   Borrowed varchar(50),
   Ordered varchar(50) )

INSERT INTO book VALUES (10001,'oracle��������','������','ˮ��������','2003.1.12','��','��');
INSERT INTO book VALUES (10002,'���ݿ���Ŀ����','���˻�','�廪������','2003.3.16','��','��');
INSERT INTO book VALUES (10003,'��ѧӢ��','����','���ĳ�����','2007.1.12','��','��');
INSERT INTO book VALUES (10004,'����','����','����������','2003.1.12','��','��');
INSERT INTO book VALUES (10005,'Ӣ���ȫ','jeans','���ĳ�����','2003.1.12','��','��');
INSERT INTO book VALUES (10006,'���������','лϣ��','�߽̳�����','2003.11.04','��','��');
INSERT INTO book VALUES (10007,'����Ӣ��','����','�Ļ�������','2003.3.12','��','��');
INSERT INTO book VALUES (10008,'��ֵ����','���ĳ�','ʵ��������','2008.1.15','��','��');
INSERT INTO book VALUES (10009,'java me','��һ��','�����ʵ������','2004.1.12','��','��');
INSERT INTO book VALUES (10010,'˼������','�⿡','ͬ�ô�ѧ������','2003.1.12','��','��');

select * from book

CREATE TABLE exceedtime (
  StuNO int NOT NULL DEFAULT '0' ,
  BookNO int DEFAULT NULL,
  BookName varchar(50) DEFAULT '',
  DelayTime int,
  PRIMARY KEY (StuNO,BookName))

INSERT INTO exceedtime VALUES (10001,10001,'oracle��������',50);
INSERT INTO exceedtime VALUES (10002,10002,'���ݿ���Ŀ����',50);
INSERT INTO exceedtime VALUES (10003,10001,'oracle��������',50);
INSERT INTO exceedtime VALUES (10004,10002,'���ݿ���Ŀ����',50);

select * from exceedtime

CREATE TABLE losebook (
  LBNO int NOT NULL,
  StuNO int DEFAULT NULL,
  BookNO int DEFAULT NULL,
  BookName varchar(50) DEFAULT NULL,
  PRIMARY KEY (LBNO)  )

CREATE TABLE manager (
  mgNo int NOT NULL,
  permitted varchar(50) DEFAULT NULL,
  password varchar(50) DEFAULT NULL,
  PRIMARY KEY (mgNo)) 

INSERT INTO manager VALUES (1001,'1','1001');

select * from manager

CREATE TABLE orderreport (
  BookNO int NOT NULL,
  StuName varchar(50) DEFAULT NULL,
  Class varchar(50) DEFAULT NULL,
  BookName varchar(50) DEFAULT NULL,
  StuNO int DEFAULT NULL,
  Author varchar(50) DEFAULT NULL,
  PRIMARY KEY (BookNO)  ) 

CREATE TABLE record (
  BookNO int NOT NULL,
  StuNO int DEFAULT NULL,
  BorrowTime varchar(50) DEFAULT NULL,
  ReturnTime varchar(50) DEFAULT NULL,
  Borrowed varchar(50) DEFAULT NULL,
  Ordered varchar(50) DEFAULT NULL,
  PRIMARY KEY (BookNO)) 


CREATE TABLE student (
  StuNO int NOT NULL,
  StuName varchar(50) DEFAULT NULL,
  StuAge int DEFAULT NULL,
  StuSex varchar(50) DEFAULT NULL,
  Class varchar(50) DEFAULT NULL,
  Department varchar(50) DEFAULT NULL,
  Tel char(11) DEFAULT NULL,
  Permitted varchar(50) DEFAULT NULL,
  Password varchar(20) DEFAULT NULL,
  PRIMARY KEY (StuNO) ) 

INSERT INTO student VALUES (10001,'��Сʫ',20,'Ů','�����1��','�����ϵ','2592921','��','number1');
INSERT INTO student VALUES (10002,'���',21,'Ů','�����1��','�����ϵ','13730120123','��','number2');
INSERT INTO student VALUES (10003,'����',20,'��','�����1��','�����ϵ','13633654578','��','number3');
INSERT INTO student VALUES (10004,'�ζ�',22,'��','�����1��','�����ϵ','2568975','��','number4');
INSERT INTO student VALUES (10005,'����',21,'Ů','�����1��','�����ϵ','13936968956','��','number5');
INSERT INTO student VALUES (10006,'�ν�',20,'��','�����2��','�����ϵ','1234667','��','number6');

select * from student