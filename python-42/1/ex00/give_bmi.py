def is_number(n: str) -> bool:
    """Check if n can be a float or int"""
    try:
        if (float(n) != float(n)):
            return (False)
    except ValueError:
        return False
    return True


def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """
    give_bmi, take 2 lists of integers
    or floats in input and returns a list of BMI values.
    """
    if (len(height) != len(weight)):
        print("Error: give_bmi: height length != weight length")
        return []
    res: list[int | float] = []
    for h, w in zip(height, weight):
        if not is_number(h) or not is_number(w):
            print("Error: give_bmi: all entries must be numbers")
            return []
        res.append(w/(h*h))
    return res


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    accepts a list of integers or floats and an integer representing
    a limit as parameters.
    It returns a list of booleans (True if above the limit).
    """
    res = []
    if (not is_number(limit)):
        print("Error: apply_limit: limit must be a number")
        return []
    for i in bmi:
        if not is_number(i):
            print("Error: apply_limit: all entries must be a number")
            return []
        res.append(i > limit)
    return res
