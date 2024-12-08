import sys

def travelingSalesman(remainingCities, memo, current, dist): 
    if not remainingCities:
        return dist[current][0]
 
    key = (current, set(remainingCities))
    
    if key in memo:
        return memo[key]

    ans = sys.maxsize

    for city in remainingCities:
        newCities = remainingCities - {city}
        cost = dist[current][city] + travelingSalesman(newCities, memo, city, dist)
        ans = min(ans, cost)

    memo[key] = ans
    return ans

if __name__ == "__main__":
    dist = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0],
    ]
    n = len(dist)
    remainingCities = set(range(1, n))  # Exclude the start city (0)
    memo = {}

    result = travelingSalesman(remainingCities, memo, 0, dist)
    print("The minimum cost of visiting all cities is:", result)
