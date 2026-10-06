import sys
import string


def get_prompt():
    """
    A function to get the prompt in uppercase from the sys args
    -> returns str
    """
    args = sys.argv
    try:
        if (len(args) != 2):
            raise AssertionError("there should be only 1 arg")
        arg = args[1].upper()
        arg_filter = filter(lambda c: c not in
                            string.ascii_uppercase
                            + string.whitespace
                            + string.digits,
                            arg)
        if len(list(arg_filter)) > 0:
            raise AssertionError("the arguments are bad")
        return (arg)
    except AssertionError as e:
        print(AssertionError.__name__ + ":", e)
        exit(1)


def main():
    """Main function"""
    s = get_prompt()
    morse_code_dict = {
        # Letters (A-Z)
        'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
        'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-',
        'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
        'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-',
        'V': '...-', 'W': '.--', 'X': '-..-',
        'Y': '-.--', 'Z': '--..',
        # Numbers (0-9)
        '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-',
        '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.',
        # Space
        ' ': '/'
    }
    for i in range(len(s)):
        print(morse_code_dict[s[i]], end='')
        if (i != len(s) - 1):
            print(' ', end='')
    print()


if __name__ == "__main__":
    main()
