import sys

args = sys.argv

def is_number(n: str) -> bool:
    try:
        if (float(n) != float(n)):
            return (False)
    except:
        return False
    return True

try:
    if (len(args) == 1):
        exit(0)
    if (len(args) > 2):
        raise AssertionError("more than one argument is provided")
    if (not is_number(args[1])):
        raise AssertionError("argument is not an integer")
    n = int(args[1])
    if (n % 2 == 0):
        print("I'm Even.")
    else:
        print("I'm Odd.")
except AssertionError as e:
    print(AssertionError.__name__ + ":", e)
