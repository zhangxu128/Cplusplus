#猜数字小游戏
import random
print('我们一起猜猜猜')
temp=int(input("请输入"))
guess=random.randint(1,20)
while 1:
    if temp==guess:
        print("厉害了，猜对了")
        break
    elif temp<guess:
        print('小了，再猜')
        temp=int(input("请输入"))
    else:
        print('大了，再猜')
        temp=int(input("请输入"))
