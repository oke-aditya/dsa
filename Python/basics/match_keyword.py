def http_error(status: int) -> str:
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "Not found"
        case 418:
            return "I'm a teapot"
        
        case 401 | 401 | 403:
            return "Not allowed"

        # Wild card in case nothing matches        
        case _:
            return "Internet is broken"


class Point:
    x: int
    y: int


def point_matcher(point: Point) -> str:
    match point:
        case point(x=0, y=0):
            return "Origin"
        case point(x=x, y=0):
            return f"X axis (x) = {x}"
        case point(x=0, y=y):
            return f"Y axis (y) = {y}"
        case Point():
            return f"X axis (x) = {x}, Y axis (y) = {y}"
        case _:
            return "Not a point"
        

