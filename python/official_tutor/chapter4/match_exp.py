def main():
    point = (5, 5)
    match point:
        case (0, 0):
            print("Origin")
        case (x, 0):
            print(f"X={x}")
        case (0, y): 
            print(f"Y={y}")
        case (x, y):
            print(f"X={x}, Y={y}")
        case _:
            raise ValueError
    return

if __name__ == '__main__':
    main()
