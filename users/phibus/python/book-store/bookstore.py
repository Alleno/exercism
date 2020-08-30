from copy import deepcopy
from itertools import groupby

def total(basket):
    value = 0
    basket0 = deepcopy(basket)
    while len (basket) >= 8:
        basket, value = treat_4 (basket, value)
    if basket == []:
        return value
    return min(value + value_lot(basket), value_lot(basket0))


def treat_4 (basket, value):
    keys, groups = [], []
    for key, group in groupby(sorted(basket)):
        keys.append(key)
        groups.append(list(group))
    if len(keys) == 5:
        u = [group for group in groups if len(group) == min([len(group) for group in groups])][0][0]
        keys.remove(u)
        for key in keys:
            basket.remove(key)
        print(basket)
        basket = deepcopy(basket)
        value += (800 * 4 * 0.80)
        return basket, value


def value_lot(lot):
    value = 0
    while len(lot) > 0:
        keys = []
        for key, _ in groupby(sorted(lot)):
            keys.append(key)
        if len(keys) == 5:
            value += 800 * 5 * 0.75
        if len(keys) == 4:
            value += 800 * 4 * 0.80
        if len(keys) == 3:
            value += 800 * 3 * 0.90
        if len(keys) == 2:
            value += 800 * 2 * 0.95
        if len(keys) == 1:
            value += 800 * 1
        for key in keys:
            lot.remove(key)
    return value

print(total([1,2,3,4,5]))

