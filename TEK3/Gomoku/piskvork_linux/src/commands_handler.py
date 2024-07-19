from src.brain import Brain
from src.utils import pipeOut, safeInt
from sys import stdin


def parse_3int_chk(param):
    """parse coordinates x,y and player number z"""
    if param.count(",") != 2:
        return None, None, None
    x, y, z = param.split(",")
    x, y, z = [safeInt(v) for v in (x, y, z)]
    if any(v is None for v in (x, y, z)):
        return None, None, None
    return x, y, z


class CommandsHandler:
    def __init__(self, brain: Brain):
        self.brain: Brain = brain
        self.is_inited = False
        self.size = (0, 0)
        self.is_empty = True

    def start(self, size: int):
        self.brain.init_brain(size, size)
        self.is_inited = True
        self.size = (size, size)
        self.is_empty = True

    def restart(self, size: int):
        self.start(size)
        self.is_empty = True

    def rect_start(self, width: int, height: int):
        self.brain.init_brain(width, height)
        self.is_inited = True
        self.size = (width, height)
        self.is_empty = True

    def turn(self, x: int, y: int):
        self.brain.opponent_turn(x, y)
        self.brain.turn()
        self.is_empty = False

    def begin(self):
        self.brain.turn()
        self.is_empty = False

    def end(self):
        self.brain.end()

    def board(self):
        if not self.is_inited:
            pipeOut("ERROR not initialized")
            return
        elif not self.is_empty:
            pipeOut("ERROR not an empty board")
            return
        while True:
            cmd = stdin.readline().strip()
            if " " in cmd:
                pipeOut("ERROR invalid command")
                return
            x, y, who = parse_3int_chk(cmd)
            if cmd.lower() == "done":
                break
            if x is None or y is None or x < 0 or y < 0 or who < 0 or x >= self.size[0] or y >= self.size[1] or who > 3:
                pipeOut("ERROR invalid coordinates or user")
                return
            elif who == 1:
                self.brain.mock_my_turn(x, y)
            elif who == 2:
                self.brain.opponent_turn(x, y)
            elif who == 3:
                self.brain.block(x, y)

        self.brain.turn()
        self.is_empty = False

    def about(self):
        self.brain.about()

    def info(self, key, value):
        self.brain.info(key, value)
