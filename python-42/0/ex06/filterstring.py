import sys
from ft_filter import ft_filter


def is_int(n: str) -> bool:
    """Checks if the str is convertible to an int"""
    try:
        int(n)
    except ValueError:
        return False
    return True


def get_prompt():
    """A function to get the prompt from the user from args str, int"""
    args = sys.argv
    try:
        if (len(args) != 3):
            raise AssertionError("there should be only 2 args")
        if (not is_int(args[2])):
            raise AssertionError("second arg should be an int")
        return (args[1], int(args[2]))
    except AssertionError as e:
        print(AssertionError.__name__ + ":", e)
        exit(1)


def main():
    """Main function"""
    s, n = get_prompt()
    words = s.split()
    print(ft_filter(lambda c: len(c) > n, words))


if __name__ == "__main__":
    main()
