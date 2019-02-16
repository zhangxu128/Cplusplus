# Host: localhost    Database: test1
# ------------------------------------------------------
# Server version 5.5.15

DROP DATABASE IF EXISTS `test`;
CREATE DATABASE `test` /*!40100 DEFAULT CHARACTER SET gbk */;
USE `test`;

#
# Source for table admininfo
#

DROP TABLE IF EXISTS `admininfo`;
CREATE TABLE `admininfo` (
  `Aid` int(11) NOT NULL,
  `Aname` varchar(50) NOT NULL,
  `Apwd` varchar(20) NOT NULL,
  `Alevel` varchar(10) DEFAULT '普通',
  PRIMARY KEY (`Aid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

#
# Dumping data for table admininfo
#
LOCK TABLES `admininfo` WRITE;

INSERT INTO `admininfo` VALUES (10001,'wyf','123456','超级');
INSERT INTO `admininfo` VALUES (10002,'zrk','123456','普通');
UNLOCK TABLES;

#
# Source for table goodsinfo
#

DROP TABLE IF EXISTS `goodsinfo`;
CREATE TABLE `goodsinfo` (
  `Gid` int(11) NOT NULL,
  `Gname` varchar(100) NOT NULL,
  `Gprice` double NOT NULL,
  `Gclass` varchar(50) DEFAULT '杂货',
  `Gamount` int(11) NOT NULL,
  `Gdate` datetime DEFAULT NULL,
  `Gimgurl` varchar(100) DEFAULT 'img/default.jpg',
  `Glook` int(11) DEFAULT '0',
  `Gintro` text,
  `Gbrief` text,
  PRIMARY KEY (`Gid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

#
# Dumping data for table goodsinfo
#
LOCK TABLES `goodsinfo` WRITE;

INSERT INTO `goodsinfo` VALUES (807200001,'Fuwa\'s Olympic Stories',367,'DVD',100,'2008-05-01','img/DVD/807200001.jpg',0,'导演:曾伟京|集数:100集|碟片数:10|介质:DVD','片子讲述的故事发生在2008年第29届奥运会开幕前夕。在邻近主会场“鸟巢”的居民楼里，居住着一户三口之家。孩子大友的爸爸妈妈在他8岁生日的这一天，送给他一套奥运吉祥物“福娃”作为礼物，这一天开始“福娃”和大友原来的“卡酷”玩具之间发生了很多有趣的故事。通过这些故事，展现了奥运体育项目的起源与发展、规则的制定与完善以及令人惊叹的奥运史上的经典故事。');
INSERT INTO `goodsinfo` VALUES (807200002,'那山那人那狗(DVD)',30,'DVD',100,'2008-07-15','img/DVD/807200002.jpg',0,'导演:霍建起|主演：滕汝骏,刘烨|片长：127分钟|碟片数：1|介质:DVD','即将退休的乡邮员，在湖南茫茫的深山中送了一辈子信，马上要由唯一的儿子接下送信的工作，面对儿子第一次出发老邮员千叮万嘱交代，实在放心不下，于是带着长年跟随的忠狗陪着儿子走一趟送信之旅。徒步在壮阔的山林。清翠的田野间，这一对父子展开前所未有的认识和了解，年轻气盛的儿子终于了解数十年来，父亲邮差工作的辛苦与意义。老乡邮员也体会20多年来，妻子终日等待的无奈和儿子长大成人的骄傲。于是那山那水，那狗构筑了一幅幅美丽的画面一串串人性的感动。');
INSERT INTO `goodsinfo` VALUES (807200003,'功夫之王(简装DVD)',14,'DVD',50,'2008-06-15','img/DVD/807200003.jpg',0,'导演：罗伯·民可夫|主演：成龙,李连杰,刘亦菲,李冰冰|片长：94分钟|碟片数：1|介质：DVD','一个夏日，这个十七岁的男孩骑着脚踏车，到波士顿唐人街的一家当铺寻找具有收藏价值的中国功夫片，但他总是在穿过自己家附近的巷子时遇到麻烦，因为杰森经常被一群混混盯上，并且常受到他们的欺负。杰森精通电子游戏，对于功夫片也是如数家珍，他总是希望自己也能成为一名功夫高手，然而当铺的老板老霍却认为，杰森根本不是这块料，他根本不知道什么是功夫。');
INSERT INTO `goodsinfo` VALUES (807200004,'功夫',30,'DVD',20,'2008-03-21','img/DVD/807200004.jpg',0,'导演：周星驰|主演：周星驰，黄圣依，梁小龙，元华，元秋|片长：95分钟|碟片数：1|介质：DVD','故事发生在20世纪40年代的中国，周星驰饰演一个一事无成、小偷小摸的古惑仔，立志加入当时势力最大、手段残忍的黑帮“斧头帮”。星仔试图在一个叫“猪笼城寨”的地方对居民敲诈，却不知道他们个个身怀绝技，结果在这里栽了跟头。星仔与居民的冲突不经意地将“斧头帮”戏剧性地卷入其中，正反两派之间的斗争正式展开。从“猪笼城寨”居民为生存而战发展到两派武术高手间的交锋，星仔渐渐地放弃了从前的思想和志向，开始领悟功夫的真谛。');
INSERT INTO `goodsinfo` VALUES (807200005,'武状元苏乞儿',7,'DVD',15,'2008-07-20','img/DVD/807200005.jpg',0,'主演：周星驰，吴孟达，张敏|片长：101分钟|碟片数：1|介质：DVD','苏查哈尔灿生活在大将军府邸，武功高强，但性格狂放。因爱如霜姑娘而竞考武状元。但因考官舞弊，被皇上御贬终身乞讨。与曾经奢靡生活简直天壤之别，一时不振，只是睡觉。忽然一天，被丐帮创始人洪七公传入梦中点醒。学会了睡觉罗汉拳，并做了帮助之位。领导丐帮灭反贼，救皇上，永垂青史。');
INSERT INTO `goodsinfo` VALUES (807200006,'朗文外研社新概念英语.1',47.9,'图书',10,'2008-04-10','img/book/807200006.jpg',0,'作者：（英）亚历山大（Alexander,L.G.），何其莘 合作编著|出版社：外语教学与研究出版社|出版时间： 2007-7-1','本版是《新概念英语》首次出版以来第一次推出的新版本。这套经典教材一如既往向读者提供一个完整的、经过实践检验的英语学习体系，使学生有可能在英语的4项基本技能一理解、口语、阅读和写作一方面最大限度地发挥自己的潜能。');
INSERT INTO `goodsinfo` VALUES (807200007,'笑死我的英文书',29.8,'图书',12,'2008-07-15','img/book/807200007.jpg',0,'作者：（加）可可 编著|出版社：中国广播电视出版社|出版时间：2007-10-1','这是一本集图像、幽默、联想于一身的简单易学的英文书。本书系统化归纳整理出164个常犯的中式英语错误，素材均来源于生活。在编写过程中，作者另辟蹊径，将轻松活泼的故事和常用词汇巧妙融合其中，再配以幽默的图片，让人过目不忘，轻轻松松提高英文水平。本书的每篇文章均配有中文翻译，适合各个水平的读者学习使用。');
INSERT INTO `goodsinfo` VALUES (807200008,'生活英语情景口语100主题',38,'图书',20,'2008-06-30','img/book/807200008.jpg',0,'作者：（美）罗克特，王恩波 著|出版社：外文出版社|出版时间： 2007-6-1','本书越过了“生存口语”的层次，深入到社会生活的细微之处。与同类型的书相比，拥有更广泛的话题、更生动的表达、更浓厚趣味。作者Carol Rueckert是资深的英语教学专家，又深入英美社会生活多年。她用100个场景、200篇对话细致展现了当下英美的风土人情，以及英语国家普通百姓的沟通方式。本书将帮助你突破口语瓶颈，实现多话题、深层次的英语交流。');
INSERT INTO `goodsinfo` VALUES (807200009,'新托福考试综合教程',148,'图书',15,'2008-06-30','img/book/807200009.jpg',0,'作者：（美）菲利普斯（Phillips,D.）著|出版社：世界图书出版公司|出版时间：2006-1-1','本书完全按照新托福考试标准编写，是一本综合性的语言技能提高教程。书中涵盖了新托福考试各分项测试的题型剖析及技能讲解，并提供大量的模拟题目供考生自测。本书英文版在国际上享有盛誉，新东方独家引进后，对其进行了二次研发，以满足中国读者的学习特点和需求，是考生备考新托福的首选权威参考书。');
UNLOCK TABLES;

#
# Source for table ordergoods
#

DROP TABLE IF EXISTS `ordergoods`;
CREATE TABLE `ordergoods` (
  `OGid` int(11) NOT NULL,
  `Oid` int(11) NOT NULL,
  `Uid` int(11) NOT NULL,
  `Gid` int(11) NOT NULL,
  `OGamount` int(11) NOT NULL,
  `OGtotalprice` double NOT NULL,
  PRIMARY KEY (`OGid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

#
# Dumping data for table ordergoods
#
LOCK TABLES `ordergoods` WRITE;

UNLOCK TABLES;

#
# Source for table orderinfo
#

DROP TABLE IF EXISTS `orderinfo`;
CREATE TABLE `orderinfo` (
  `Oid` int(11) NOT NULL,
  `Odate` datetime NOT NULL,
  `Aid` int(11) DEFAULT NULL,
  `Ostate` varchar(20) DEFAULT NULL,
  `Orecname` varchar(50) NOT NULL,
  `Orecadr` varchar(200) NOT NULL,
  `Orectel` varchar(20) DEFAULT NULL,
  `Uid` int(11) DEFAULT NULL,
  `Ototalprice` double DEFAULT NULL,
  PRIMARY KEY (`Oid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

#
# Dumping data for table orderinfo
#
LOCK TABLES `orderinfo` WRITE;

UNLOCK TABLES;

#
# Source for table userinfo
#

DROP TABLE IF EXISTS `userinfo`;
CREATE TABLE `userinfo` (
  `Uid` int(11) NOT NULL,
  `Uname` varchar(50) NOT NULL,
  `Upwd` varchar(20) NOT NULL,
  `Uemail` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`Uid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

#
# Dumping data for table userinfo
#
LOCK TABLES `userinfo` WRITE;

INSERT INTO `userinfo` VALUES (10001,'zrk','860607','www.zrk@163.com');
INSERT INTO `userinfo` VALUES (10002,'wyy','871216','www.wyy@163.com');
UNLOCK TABLES;

