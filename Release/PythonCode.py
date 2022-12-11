import re
import string


#Read file and reate a useable dictionary of data for other functions
# I would have created a cached dictionary as a global or in a class but was unsure of how to do so since the main is in a c++ scope
def CreateDicOfDailyItems():
    file = open('Day1Items.txt', 'r')
    Lines = file.readlines()
    file.close()

    itemDic = {}
    for line in Lines:
        itemName = line.strip()
        if itemName in itemDic.keys():
            itemDic[itemName.capitalize()] += 1
        else:
            itemDic[itemName.capitalize()] = 1

    return itemDic

def OutputAllItems():
    itemDic = CreateDicOfDailyItems()

    if itemDic:
        for key, value in itemDic.items():
            print("{}: {}".format(key, value))
    else:
        print("No items")

    return 0
    
def ItemOccurrence(item):
    dic = CreateDicOfDailyItems()

    if item.capitalize() in dic.keys():
        print("{}: {}".format(item.capitalize(), dic[item.capitalize()]))
    else:
        print("{} not found.".format(item))
        
    return 0

def ItemHistogram():
    dic = CreateDicOfDailyItems()
    
    datFile = open("frequency.dat", "w")

    for item in dic:
        datFile.write("{} {}\n".format(item, dic[item]))

    datFile.close()