def is_subString(s1, s2):
    if s2 in s1:
        return True
    return False

def is_rotation(s1, s2):
    return is_subString(s1 + s1, s2)

first_string = "waterbottle"
second_string = "erbottlewat"
assert is_rotation(first_string, second_string)

first_string = "water"
second_string = "haha"
assert not is_rotation(first_string, second_string)
