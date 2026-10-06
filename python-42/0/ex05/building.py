import sys
import string


def get_prompt() -> str:
    """A function to get the prompt from the user from args or from stdin"""
    args = sys.argv
    try:
        if (len(args) == 1):
            return input()
        elif (len(args) > 2):
            raise AssertionError("more than one argument is provided")
        return args[1]
    except AssertionError as e:
        print(AssertionError.__name__ + ":", e)
        exit(1)


def main():
    """Main function"""
    prompt = get_prompt()
    uppers = 0
    lowers = 0
    punctuation = 0
    digits = 0
    spaces = 0

    for c in prompt:
        if c in string.ascii_uppercase:
            uppers += 1
        elif c in string.ascii_lowercase:
            lowers += 1
        elif c in string.punctuation:
            punctuation += 1
        elif c in string.digits:
            digits += 1
        elif c in string.whitespace:
            spaces += 1
    print(f"The text contains {len(prompt)} characters:")
    print(f"{uppers} upper letters")
    print(f"{lowers} lower letters")
    print(f"{punctuation} punctuation marks")
    print(f"{spaces} spaces")
    print(f"{digits} digits")


if __name__ == "__main__":
    main()
