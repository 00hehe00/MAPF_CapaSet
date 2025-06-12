import random


def generate_agents(n):
    with open('agents.txt', 'w') as file:
        for i in range(1, n + 1):
            random_value = round(random.uniform(0, 0.6), 1)
            if random_value ==0:
                random_value+=0.1
            line = f"agent{i}: {random_value}\n"
            file.write(line)


# 示例：生成到 agent20
n = 24
generate_agents(n)
