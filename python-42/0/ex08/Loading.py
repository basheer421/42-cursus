from os import get_terminal_size


def print_bar(curr: int, total: int):
    """Helper function for ft_tqdm(). Used to printing only."""
    BEFORE_BAR = 5
    AFTER_BAR = 25
    percent = int((curr / total) * 100)
    cols = get_terminal_size().columns - BEFORE_BAR - AFTER_BAR\
        - len(str(percent) + str(curr) + str(total))
    bars = "█"*int(percent/100 * cols)
    spaces = " " * (cols - len(bars))
    print(f"\r{percent}%|{bars+spaces}| {curr}/{total}", end='', flush=True)


def ft_tqdm(lst: range) -> None:
    """A funtion used for progress"""
    size = len(lst)
    for _, val in enumerate(lst):
        print_bar(val + 1, size)
        yield val
