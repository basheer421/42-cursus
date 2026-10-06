from types import FunctionType


def ft_filter(f: FunctionType, iterable: iter) -> iter:
    """filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true."""
    return [i for i in iterable if f(i)]
