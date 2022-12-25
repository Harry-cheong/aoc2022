f = open(r"C:\Users\harry\Desktop\Computing\aoc2022\aoc2022\Day 9\input.txt", "r")
score = 0
tail = [0, 0] #x, y
head = [0, 0] #x, y

positions_visited = ["0-0"]

for line in f:
    direction, count = line.split()
    count = int(count)
    for _ in range(count):
        if direction == "U":
            head[1] += 1
        elif direction == "D":
            head[1] -= 1
        elif direction == "R":
            head[0] += 1
        elif direction == "L":
            head[0] -= 1

        if (abs(head[0]-tail[0]) > 1 and abs(head[1]-tail[1]) >= 1) or (abs(head[0]-tail[0]) >= 1 and abs(head[1]-tail[1]) > 1):
            if head[0] > tail[0]: tail[0] += 1
            elif head[0] < tail[0]: tail[0] -= 1
            if head[1] > tail[1]: tail[1] += 1
            elif head[1] < tail[1]: tail[1] -= 1
        else:
            if abs(head[0]-tail[0]) > 1:
                if head[0] > tail[0]: tail[0] += 1
                elif head[0] < tail[0]: tail[0] -= 1
            if abs(head[1]-tail[1]) > 1:
                if head[1] > tail[1]: tail[1] += 1
                elif head[1] < tail[1]: tail[1] -= 1

        positions_visited.append(f"{tail[0]}-{tail[1]}")

print(len(set(positions_visited))) # Answer: 6181