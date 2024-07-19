from src.debug import Debug
from enum import Enum


class Patterns:
    def __init__(self, player: int, opponent: int, empty: int, debug=None):
        self.debug: Debug = debug
        self.patterns = [
            (self.pattern_fork_A, 100000),
            (self.pattern_fork_B, 100000),
            (self.pattern_fork_C, 50000),
            (self.pattern_fork_D, 100000),
            (self.pattern_three_A, 1000),
            (self.pattern_three_B, 1000),
            (self.pattern_four_A, 100000),
            (self.pattern_four_B, 100000),
        ]

        class Matching(Enum):
            PLAYER = player
            OPPONENT = opponent
            EMPTY = empty

        self.pattern_array = {
            "forkA": [
                (0, 0, Matching.EMPTY),
                (0, -1, Matching.PLAYER),
                (0, -2, Matching.PLAYER),
                (0, -3, Matching.PLAYER),
                (-1, -1, Matching.PLAYER),
                (-2, -2, Matching.PLAYER),
            ],
            "forkB": [
                (0, 0, Matching.EMPTY),
                (1, 0, Matching.PLAYER),
                (2, 0, Matching.PLAYER),
                (0, -1, Matching.PLAYER),
                (1, -2, Matching.PLAYER),
                (2, -3, Matching.PLAYER),
            ],
            "forkC": [
                (0, 0, Matching.EMPTY),
                (0, -1, Matching.PLAYER),
                (1, -2, Matching.PLAYER),
                (2, -3, Matching.PLAYER),
                (1, 0, Matching.PLAYER),
                (-1, 0, Matching.PLAYER),
            ],
            "forkD": [
                (0, 0, Matching.EMPTY),
                (1, 0, Matching.EMPTY),
                (2, 0, Matching.PLAYER),
                (3, 0, Matching.PLAYER),
                (-1, -1, Matching.PLAYER),
                (1, 1, Matching.EMPTY),
                (2, 2, Matching.PLAYER),
                (3, 3, Matching.PLAYER),
            ],
            "threeA": [
                (0, 0, Matching.EMPTY),
                (1, 0, Matching.PLAYER),
                (0, -1, Matching.PLAYER),
            ],
            "threeB": [
                (0, 0, Matching.EMPTY),
                (1, 1, Matching.PLAYER),
                (1, -1, Matching.PLAYER),
            ],
            "fourA": [
                (0, 0, Matching.EMPTY),
                (1, 0, Matching.PLAYER),
                (0, -1, Matching.PLAYER),
                (0, -2, Matching.PLAYER),
            ],
            "fourB": [
                (0, 0, Matching.EMPTY),
                (1, 1, Matching.PLAYER),
                (-1, -1, Matching.PLAYER),
                (-2, -2, Matching.PLAYER),
            ],
        }

    def rotate_pattern(self, pattern, angle):
        if angle == 0:
            return pattern
        elif angle == 90:
            return [(y, -x, player) for x, y, player in pattern]
        elif angle == 180:
            return [(-x, -y, player) for x, y, player in pattern]
        elif angle == 270:
            return [(-y, x, player) for x, y, player in pattern]

    def check_pattern(self, x, y, pattern, board):
        for angle in [0, 90, 180, 270]:
            if all(
                board[y + pos_y][x + pos_x] == player for pos_x, pos_y, player in self.rotate_pattern(pattern, angle)
            ):
                self.debug.log(f"Pattern found: {pattern} {angle}", 2)
                return True
        return False

    def pattern_fork_A(self, x, y, board, player):
        if x < 3 or y < 3 or x > 12 or y > 12:
            return False
        return self.check_pattern(x, y, self.pattern_array["forkA"], board)

    def pattern_fork_B(self, x, y, board, player):
        if x < 3 or y < 3 or x > 12 or y > 12:
            return False
        return self.check_pattern(x, y, self.pattern_array["forkB"], board)

    def pattern_fork_C(self, x, y, board, player):
        if x < 3 or y < 3 or x > 12 or y > 12:
            return False
        return self.check_pattern(x, y, self.pattern_array["forkC"], board)

    def pattern_fork_D(self, x, y, board, player):
        if x < 3 or y < 3 or x > 12 or y > 12:
            return False
        return self.check_pattern(x, y, self.pattern_array["forkD"], board)

    def pattern_three_A(self, x, y, board, player):
        if x < 2 or y < 2 or x > 13 or y > 13:
            return False
        return self.check_pattern(x, y, self.pattern_array["threeA"], board)

    def pattern_three_B(self, x, y, board, player):
        if x < 2 or y < 2 or x > 13 or y > 13:
            return False
        return self.check_pattern(x, y, self.pattern_array["threeB"], board)

    def pattern_four_A(self, x, y, board, player):
        if x < 3 or y < 3 or x > 12 or y > 12:
            return False
        return self.check_pattern(x, y, self.pattern_array["fourA"], board)

    def pattern_four_B(self, x, y, board, player):
        if x < 3 or y < 3 or x > 12 or y > 12:
            return False
        return self.check_pattern(x, y, self.pattern_array["fourB"], board)
