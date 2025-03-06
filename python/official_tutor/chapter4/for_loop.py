def main():
    users = {'Hans': 'active', 'Éléonore': 'inactive', '景太郎': 'active'}
    for user, status in users.copy().items():
        if status == 'inactive':
            del users[user]

    active_users = {}
    for user, status in users.items():
        if status == 'active':
            active_users[user] = status

    a = ['Mary', 'had', 'a', 'little', 'lamb']
    for i in range(len(a)):
        print(i, a[i])

    while True:
        pass

if __name__ == '__main__':
    main()
