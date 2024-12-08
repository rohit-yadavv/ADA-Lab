import sys

def travelingSalesman(currentCity, remainingCities, dist, memo):
    if not remainingCities:
        return dist[currentCity][0]
    
    key = (currentCity, frozenset(remainingCities))
    if key in memo:
        return memo[key]

    ans = sys.maxsize

    for city in remainingCities:
        newCities = remainingCities - {city}
        cost = dist[currentCity][city] + travelingSalesman(city, newCities, dist, memo)
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
    remainingCities = frozenset(range(1, n))  # Exclude the start city (0)
    memo = {}

    result = travelingSalesman(0, remainingCities, dist, memo)
    print("The minimum cost of visiting all cities is:", result)
