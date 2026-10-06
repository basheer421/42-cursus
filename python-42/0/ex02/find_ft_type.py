def all_thing_is_obj(object: any) -> int:
    det = str(type(object))
    name_only = det[det.find('\'') + 1: det.rfind('\'')]

    if (type(object) is str):
        s = str(object)
        print(s, "is in the kitchen", end="")
    elif (type(object) is int):
        print("Type not found")
        return 42
    else:
        print(name_only.capitalize(), end="")
    print( " : " + det)
    return 42

