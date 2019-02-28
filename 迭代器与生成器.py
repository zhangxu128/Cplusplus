import sys
#导入包

list=[1,'a',2,'b',3]
it= iter(list)
for i in it:
    try:
        print(next(it))
    except StopIteration:
        sys.exit()
'''异常处理'''


