# def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
#       -----------    ----------     ----------
#         |             |                  |
#         |        Positional or keyword   |
#         |                                - Keyword only
#          -- Positional only


def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
    pass


# Lambda fn

def make_incrementor(n: int):
    return lambda x: x + n 

# equivalent code 

if __name__ == "__main__":
    f = make_incrementor(10)
    print(f(0))




