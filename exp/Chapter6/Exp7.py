def lca(a, b):
    while(a >> 1 != b >> 1):
        if a < b:
            b >>= 1
        else:
            a >>= 1
    return a >> 1

def main():
    while True:
        try:
            a, b = map(int, input().split())
            print(lca(a, b))
        except EOFError:
            break

if __name__ == '__main__':
    main()