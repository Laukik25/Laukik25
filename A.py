import queue as Q

dict_hn = {
    'Arad': 336,
    'Bucharest': 0,
    'Craiova': 160,
    'Drobeta': 242,
    'Fagaras': 176,
    'Pitesti': 100,
    'Rimnicu': 193,
    'Sibiu': 253,
    'Timisoara': 329,
    'Zerind': 374
}

dict_gn = {
    'Arad': {'Zerind': 75, 'Timisoara': 118, 'Sibiu': 140},
    'Zerind': {'Arad': 75},
    'Timisoara': {'Arad': 118},
    'Sibiu': {'Arad': 140, 'Fagaras': 99, 'Rimnicu': 80},
    'Fagaras': {'Sibiu': 99, 'Bucharest': 211},
    'Rimnicu': {'Sibiu': 80, 'Pitesti': 97},
    'Pitesti': {'Rimnicu': 97, 'Bucharest': 101},
    'Bucharest': {}
}

start = 'Arad'
goal = 'Bucharest'

result = ""

def get_fn(path):
    cities = path.split(" -> ")
    gn = 0

    for i in range(len(cities)-1):
        gn += dict_gn[cities[i]][cities[i+1]]

    hn = dict_hn[cities[-1]]

    return gn + hn

def expand(q):
    global result

    total, path, city = q.get()

    if city == goal:
        result = path + " = " + str(total)
        return

    for next_city in dict_gn[city]:
        new_path = path + " -> " + next_city
        q.put((get_fn(new_path), new_path, next_city))

    expand(q)

def main():
    q = Q.PriorityQueue()
    q.put((get_fn(start), start, start))

    expand(q)

    print("A* Path:")
    print(result)

main()