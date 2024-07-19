from src.utils import pipeOut


class ErrorHandling:
    def __init__(self):
        self.is_inited = False

    def start(self, args):
        if len(args) != 2:
            pipeOut("ERROR")
            return False
        try:
            size = int(args[1])
            if size < 5 or size > 20:
                pipeOut("ERROR")
                return False
        except:
            pipeOut("ERROR")
            return False
        self.is_inited = True
        return True

    def turn(self, coords, board, debug):
        try:
            x = int(coords[0])
            y = int(coords[1])
            if board[x][y] is None:
                pipeOut("ERROR")
                return False
        except:
            pipeOut("ERROR")
            return False
        return True

    def begin(self, args, board):
        if board is None:
            pipeOut("ERROR")
            return False
        if len(args) != 1:
            pipeOut("ERROR")
            return False
        return True

    def end(self, args):
        if len(args) != 1:
            pipeOut("ERROR")
            return False
        return True

    def about(self, args):
        if len(args) != 1:
            pipeOut("ERROR")
            return False
        return True

    def info(self, args):
        if len(args) != 3:
            pipeOut("ERROR")
            return False
        if args[1] not in [
            "timeout_turn",
            "timeout_match",
            "max_memory",
            "time_left",
            "game_type",
            "rule",
            "evaluate",
            "folder",
        ]:
            pipeOut("ERROR")
            return False
        return True
