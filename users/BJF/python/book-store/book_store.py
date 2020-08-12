from itertools import combinations_with_replacement

def total(basket):
    if not basket:
        return 0

    ref_grouping = []
    while basket:
        unique_books = set(basket)
        num_of_unique = len(unique_books)
        ref_grouping.append(num_of_unique)

        for book in unique_books:
            basket.remove(book)
    #e.g. a reference grouping of [5,3,3] corresponds to [[1,2,3,4,5],[1,2,3],[1,2,3]]

    discounts = {5: 25, 4: 20, 3: 10, 2: 5, 1: 0} 
    prices = []
    possible = combinations_with_replacement(range(min(ref_grouping), max(ref_grouping) + 1), len(ref_grouping))
    for grouping in possible:
        if sum(grouping) == sum(ref_grouping):
            price = 0
            for number in grouping:
                price += number * (800 - 8 * discounts[number])
            prices.append(price)
    return(min(prices))