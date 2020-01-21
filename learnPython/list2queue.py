# list当作队列使用
list = [1,2,3,4,5,6,7,8,9]
while len(list) > 0:
    tmp = list[0]
    list.pop(0) #弹出索引值为0的元素
    print(tmp)
